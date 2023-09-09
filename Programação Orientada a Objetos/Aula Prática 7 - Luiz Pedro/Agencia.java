public class Agencia{
   private int numeroAgencia;
   private int proximoNumeroConta;
   private double limitePadrao;
   private double rendimentoPadrao;
   private ContaCorrente listaContaCorrente[];
   private ContaPoupanca listaContaPoupanca[];
   
   public Agencia(int numeroAgencia, double limitePadrao, double rendimentoPadrao){
      this.numeroAgencia = numeroAgencia;
      this.proximoNumeroConta = 1;
      this.limitePadrao = limitePadrao;
      this.rendimentoPadrao = rendimentoPadrao;
      this.listaContaCorrente = new ContaCorrente[20];
      this.listaContaPoupanca = new ContaPoupanca[20];
   }
   
   public int getNumeroAgencia(){
      return numeroAgencia;
   }
   
   public int getProximoNumeroConta(){
      return proximoNumeroConta;
   }   
   
   public ContaCorrente[] getListaContaCorrente(){
      return listaContaCorrente;
   }
   
   public ContaPoupanca[] getListaContaPoupanca(){
      return listaContaPoupanca;
   }
   
   public double getLimitePadrao(){
      return limitePadrao;
   }
   
   public void setLimitePadrao(double limitePadrao){
      this.limitePadrao = limitePadrao;
   }
   
   public double getRendimentoPadrao(){
      return rendimentoPadrao;
   }
   
   public void setRendimentoPadrao(double rendimentoPadrao){
      this.rendimentoPadrao = rendimentoPadrao;
   }
   
   public ContaCorrente novaContaCorrente(String nomeTitular){
      ContaCorrente novaCC = new ContaCorrente(nomeTitular, this.getNumeroAgencia(), this.getProximoNumeroConta(), this.getLimitePadrao());
      this.proximoNumeroConta++;
      for(int i=0; i<this.listaContaCorrente.length; i++){
         if(this.listaContaCorrente[i] == null){
            listaContaCorrente[i] = novaCC;
         }
      }
      return novaCC;
   }
   
   public ContaPoupanca novaContaPoupanca(String nomeTitular){
      ContaPoupanca novaCP = new ContaPoupanca(nomeTitular, this.getNumeroAgencia(), this.getProximoNumeroConta(), this.getRendimentoPadrao());
      this.proximoNumeroConta++;
      for(int i=0; i<this.listaContaPoupanca.length; i++){
         if(this.listaContaPoupanca[i] == null){
            listaContaPoupanca[i] = novaCP;
         }
      }
      return novaCP;
   }
   
   public void cobrarTaxa(Conta conta){
      System.out.println("Cobrando taxa de cesta de serviços:\n" + "Nome Titular: " + conta.getNomeTitular());
      conta.sacar(5);
   }
   
   public double balanco(Conta listaContas[]){
      double balanco = 0;
      for(int i=0; i<listaContas.length; i++){
         balanco = balanco + listaContas[i].getSaldo();
      }
      System.out.println("O balanco é: " + balanco);
      return balanco;
   }
}