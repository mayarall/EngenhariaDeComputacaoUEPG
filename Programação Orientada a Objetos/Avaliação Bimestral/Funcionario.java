public class Funcionario extends Pessoa{
   private Documento carteiraDeTrabalho;
   private double salario;
   
   public double getSalario(){
      return salario;
   }
   
   public void setSalario(double salario){
      if(salario >= 0)
         this.salario = salario;
   }
   
   public void setCarteiraDeTrabalho(Documento carteiraDeTrabalho){
      this.carteiraDeTrabalho = carteiraDeTrabalho;
   }
   
   public String toString(){
      return super.toString() + "\n" + carteiraDeTrabalho + "\nSalario: "+ getSalario();
   }
   
   public Funcionario(String nome, Documento documento, Data nascimento, String conjuge, Documento carteiraDeTrabalho, double salario){
      super(nome, documento, nascimento, conjuge);
      this.carteiraDeTrabalho = carteiraDeTrabalho;
      this.salario = salario;
   }
   
   public Funcionario(String nome, Documento documento, Data nascimento, Documento carteiraDeTrabalho, double salario){
      super(nome, documento, nascimento);
      this.carteiraDeTrabalho = carteiraDeTrabalho;
      this.salario = salario;
   }
}