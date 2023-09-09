public class ContaPoupanca extends Conta{
    private String dataAniversario;
    private double rendimento;

    public ContaPoupanca(String nomeTitular, int agencia, int numero, double rendimento){
        super(nomeTitular, agencia, numero);
        this.rendimento = rendimento;
    }

    public void setDataAniversario(String dataAniversario){
        this.dataAniversario=dataAniversario;
    }
    public String getDataAniversario(){
        return this.dataAniversario;
    }
    public void setRendimento(double rendimento){
        this.rendimento=rendimento;
    }
    public double getRendimento(){
        return this.rendimento;
    }

    public void adicionaRendimento(){
        super.saldo+=super.saldo*this.rendimento;
        System.out.println("Rendimento adicionado a poupança");
    }

    @Override
    public void depositar(double valor) {
        if(this.dataAniversario==null){
            this.dataAniversario = "17/09/2020";
        }
        super.depositar(valor);
    }

    @Override
    public String toString() {
        String dadosContaPoupanca;
        dadosContaPoupanca = "**********Conta Poupança**********\n";
        dadosContaPoupanca += super.toString();
        dadosContaPoupanca += "Data de aniversário: \t"+this.getDataAniversario()+"\n";
        dadosContaPoupanca += "Rendimento mensal: \t"+this.getRendimento()+"\n";
        return dadosContaPoupanca;
    }
}