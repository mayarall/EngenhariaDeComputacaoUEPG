import speech_recognition as sr
import time
import sim
import pyttsx3
import yaml



class Cliente:
    def __init__(self, arquivoYaml, voz='Daniel'):
        try:
            with open(arquivoYaml, 'rt', encoding='utf8') as arquivo:
                roboConfig = yaml.safe_load(arquivo)
                self.robo = roboConfig['robo']  
                self.comandoSair = roboConfig['exit']
                self.velocidade = roboConfig['speed']
                self.comandos = roboConfig['command'] 
                self.roboAtivo = True
        except IOError:
                print('Impossível abrir o arquivo de configurações')
                self.roboAtivo = False
        self.ctrlVelocidade = {'valor': 30, 'minima': 30, 'maxima': 360}    
        sim.simxFinish(-1) 
        self.id = sim.simxStart('127.0.0.1', 19999, True, True, 5000, 5) 
        self.microfone = sr.Recognizer()
        self.sintetizador = pyttsx3.init()
        vozes = self.sintetizador.getProperty('voices')  
        self.sintetizador.setProperty('voice', vozes[self.robo['voice']['value'][voz]].id) 
        self.sintetizador.setProperty('rate', 180)

    def __exit__(self, *err):
        sim.simxFinish(-1)

    def verificaConexao(self):
        contadorConecta = 1
        conectado = sim.simxGetConnectionId(self.id) != -1
        while not conectado and contadorConecta <= 5:
            print('Tentando conectar ao Copelia, tantativa', contadorConecta)
            sim.simxFinish(-1)
            self.id = sim.simxStart('127.0.0.1', 19999, True, True, 5000, 5)
            conectado = sim.simxGetConnectionId(self.id) != -1
            contadorConecta += 1
        if not conectado:
             print('Finalizando.. impossivel conectar ao Coppelia')
        return conectado

    def processarComandoVoz(self):
        with sr.Microphone() as source:
         print("Fale o comando!")
         audio = self.microfone.listen(source) 
        try:
            self.enviarComando(self.microfone.recognize_google(audio, language="pt_BR")) 
        except sr.UnknownValueError:
            pass
        except sr.RequestError as e:
            print("Erro; {0}".format(e))       

    def executarComando(self, comando, comandos):
        c = set(comando) & set(comandos)
        return len(c) != 0

    def falar(self, sentenca, fala=True):
        if fala:
            self.sintetizador.say(sentenca)
            self.sintetizador.runAndWait()

    def enviarComando(self, comando):
        if self.executarComando(self.robo['name'], comando.split()): 
            print("O robô recebeu o comando: " + comando)
            sair = self.executarComando(self.comandoSair['control'], comando.split())
            comandoValido = False
            if not sair: 
                for acao, controle in self.comandos.items():
                    if self.executarComando(controle['control'], comando.split()):
                        if controle['value'] > 0:
                            sim.simxSetIntegerSignal (self.id, 'sinalManobra', 1, sim.simx_opmode_oneshot)
                            sim.simxSetIntegerSignal(self.id, 'tipoManobra', controle['value'], sim.simx_opmode_oneshot)
                        else:
                            self.robo['manual'] = True if controle['value'] == -2 else False     
                        self.falar(controle['speech'], self.robo['voice']['enabled'])
                        comandoValido = True
                for acao, velocidade in self.velocidade.items():
                    if self.executarComando(velocidade['control'], comando.split()):
                        self.ctrlVelocidade['valor'] += velocidade['value']
                        if self.ctrlVelocidade['valor'] < self.ctrlVelocidade['minima']:
                            self.ctrlVelocidade['valor'] = self.ctrlVelocidade['minima']
                            self.falar(velocidade['warning'], self.robo['voice']['enabled'])
                        if self.ctrlVelocidade['valor'] > self.ctrlVelocidade['maxima']:
                            self.ctrlVelocidade['valor'] = self.ctrlVelocidade['maxima']
                            self.falar(velocidade['warning'], self.robo['voice']['enabled'])  
                        sim.simxSetIntegerSignal (self.id, 'sinalVelocidade', 1, sim.simx_opmode_oneshot)
                        sim.simxSetIntegerSignal(self.id, 'velocidade', self.ctrlVelocidade['valor'], sim.simx_opmode_oneshot)
                        comandoValido = True  
                        self.falar(velocidade['speech'], self.robo['voice']['enabled'])               
                if not comandoValido:
                    self.falar(self.robo['invalid'], self.robo['voice']['enabled'])
            else:
                self.falar(self.comandoSair['speech'].format(self.robo['name'][0]), self.robo['voice']['enabled'])
                self.roboAtivo = False 
        else:
            self.falar(self.robo['warning'], self.robo['voice']['enabled'])        

def main():
    cliente  = Cliente('controle.yaml')
    clienteConectado = cliente.verificaConexao()
    if clienteConectado and cliente.roboAtivo:
        cliente.runInSynchronousMode = True
        print('conexao com Copelia estabelecida') 
        cliente.falar(cliente.robo['init'].format(cliente.robo['name'][0]), cliente.robo['voice']['enabled'])
        while clienteConectado and cliente.roboAtivo:
            if cliente.robo['manual']:
                comando = input('Informe o comando: ')
                cliente.enviarComando(comando)
            else:
                cliente.processarComandoVoz()
            time.sleep(0.05)
            if cliente.roboAtivo:
                clienteConectado = cliente.verificaConexao()        

if __name__ == "__main__":
    main()