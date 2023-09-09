public class Principal {
    public static void main(String[] args){
        System.out.println("[Log] =>Criar uma Agência\n");
        
         Agencia novaAgencia = new Agencia(1, 800.0, 0.005);
         
         ContaCorrente contaC[] = new ContaCorrente[2];
         ContaPoupanca contaP[] = new ContaPoupanca[2];
        
        System.out.println("[Log => Criar uma conta Corrente e depositar R$147.00");
        contaC[0] = novaAgencia.novaContaCorrente("Professor Luiz");
        contaC[0].depositar(147.0);
        contaC[0].imprimiExtrato();
        System.out.println("[Log => Cobrar a taxa da contaC[0]");
        novaAgencia.cobrarTaxa(contaC[0]);
        contaC[0].imprimiExtrato();
        
        System.out.println("[Log => Criar uma conta Corrente e depositar R$500.00");
        contaC[1] = novaAgencia.novaContaCorrente("Maria de Souza");
        contaC[1].depositar(500.0);
        contaC[1].imprimiExtrato();
        
        System.out.println("[Log => Criar uma conta Poupança e depositar R$300.00");
        contaP[0] = novaAgencia.novaContaPoupanca("Joana da Silva");
        contaP[0].depositar(300.0);
        contaP[0].imprimiExtrato();
        System.out.println("[Log => Cobrar a taxa da contaP[0]");
        novaAgencia.cobrarTaxa(contaP[0]);
        contaP[0].imprimiExtrato();
        
        System.out.println("[Log => Criar uma conta Poupança e depositar R$100.00");
        contaP[1] = novaAgencia.novaContaPoupanca("Roberto Alves");
        contaP[1].depositar(100.0);
        contaP[1].imprimiExtrato();
        
        System.out.println("[Log => Fazer o balanço das contas Poupanças da novaAgencia:");
        novaAgencia.balanco(contaP);
        System.out.println("====================================");
        
        System.out.println("[Log => Fazer o balanço das contas Correntes da novaAgencia:");
        novaAgencia.balanco(contaC);
        System.out.println("====================================");

        
    }
}