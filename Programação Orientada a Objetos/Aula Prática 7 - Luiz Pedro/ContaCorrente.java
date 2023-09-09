public class ContaCorrente extends Conta{
    private double limite;

    public ContaCorrente(String nomeTitular, int agencia, int numero, double limite){
        super(nomeTitular, agencia, numero);
        this.limite = limite;
    }
    public void setLimite(double limite){
        this.limite = limite;
    }
    public double getLimite(){
        return this.limite;
    }


    @Override
    public void sacar(double valor){
        if(valor>=0&&valor<=this.saldo+this.limite){
            this.saldo-=valor;
            System.out.println("Sacado da conta de "+ this.getNomeTitular()+" o valor de: R$"+valor);
        }
        else if(valor >= 0 && valor > this.saldo+limite){
            System.out.println("Saldo insuficiente para sacar R$"+valor);
        }
        else{
            System.out.println("Valor de saque inválido");
        }
    }

    @Override
    public String toString(){
        String dadosConta;
        dadosConta = "**********Conta Corrente**********\n";
        dadosConta += super.toString();
        dadosConta += "Limite: \t"+this.getLimite()+"\n";
        return dadosConta;
    }
}