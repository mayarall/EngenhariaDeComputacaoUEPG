public class Funcionario extends Pessoa{
   private String registro;
   private double salario;
   
   public Funcionario(String nome, String telefone, Data nascimento, String registro, double salario){
      super(nome, telefone, nascimento);
      this.registro = registro;
      this.salario = salario;   
   }
   
   public Funcionario(String nome, Data nascimento, String registro, double salario){
      super(nome, nascimento);
      this.registro = registro;
      this.salario = salario;
   }
   
   public void setRegistro(String registro){
      this.registro = registro;
   }
   
   public String getRegistro(){
      return registro;
   }
   
   public void setSalario(double salario){
      if(salario > 0)
         this.salario = salario;
      else
         System.out.println("Valor invalido.");   
   }
   
   public final double getSalario(){
      return salario;
   }
   
   public double getSalarioComAdicional(){
      return salario;
   }
   
   public String toString(){
      return super.toString() + "\nSalario: " + salario + "\nRegistro: " + registro;
   }
   
   public void editar(String registro, double salario){
      this.registro = registro;
      this.salario = salario;
      System.out.println("Salário e Registro foram modificados.");
   }
   
   public void editar(double salario, String registro){
      this.registro = registro;
      this.salario = salario;
      System.out.println("Salário e Registro foram modificados.");
   }
   
}