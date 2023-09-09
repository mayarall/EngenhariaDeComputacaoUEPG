public class Conta {
    private String nomeTitular;
    private int agencia;
    private int numero;
    protected double saldo;

    public Conta(String nomeTitular, int agencia, int numero){
        this.nomeTitular = nomeTitular;
        this.setAgencia(agencia);
        this.setNumero(numero);
        this.saldo = 0;
    }

    public void setNomeTitular(String nomeTitular){
        this.nomeTitular = nomeTitular;
    }
    public String getNomeTitular(){
        return this.nomeTitular;
    }

    public void setAgencia(int agencia){
        if(agencia>0) {
            this.agencia = agencia;
        }
        else{
            System.out.println("Número de agência inválido");
        }
    }
    public int getAgencia(){
        return this.agencia;
    }

    public void setNumero(int numero){
        if(numero>0){
            this.numero = numero;
        }
        else{
            System.out.println("Número de conta inválido");
        }
    }
    public int getNumero(){
        return this.numero;
    }

    public double getSaldo(){
        return this.saldo;
    }

    public void setSaldo(double saldo) {
        this.saldo = saldo;
    }

    public void depositar(double valor){
        if(valor>=0){
            this.saldo+=valor;
            System.out.println("Deposito efetuado na conta de "+ this.getNomeTitular()+" o valor de: R$"+valor);
        }
        else{
            System.out.println("Valor de depósito inválido");
        }
    }
    public void sacar(double valor){
        if(valor>=0&&valor<=this.saldo){
            this.saldo-=valor;
            System.out.println("Sacado da conta de "+ this.getNomeTitular()+" o valor de: R$"+valor);
        }
        else if(valor >= 0 && valor > this.saldo){
            System.out.println("Saldo insuficiente");
        }
        else{
            System.out.println("Valor de saque inválido");
        }
    }

    public void imprimiExtrato(){
        System.out.println("====================================");
        System.out.println("==========Extrato de conta==========");
        System.out.println(this.toString());
        System.out.println("====================================");
    }

    public String toString(){
        String dadosConta;
        dadosConta = "Titular: \t"+this.getNomeTitular()+"\n";
        dadosConta += "Agência: \t"+this.getAgencia()+"\n";
        dadosConta += "Numero: \t"+this.getNumero()+"\n";
        dadosConta += "Saldo: \t\t"+this.getSaldo()+"\n";
        return dadosConta;
    }

    //Desafio
    public void transfere(double valor, Conta destinatario){
        if(valor>0&&this.saldo>=valor){
            this.saldo-=valor;
            System.out.println("Transferindo o valor de R$"+valor+" \n" +
                    "Remetente:\t"+this.getNomeTitular()+"\n"+
                    "Destinatário:\t"+destinatario.getNomeTitular());
            destinatario.depositar(valor);
        }
        else{
            System.out.println("Não foi possível realizar a transferência, verifique seu saldo.");
        }
    }
}