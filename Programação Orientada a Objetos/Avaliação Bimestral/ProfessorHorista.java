public class ProfessorHorista extends Funcionario{
   private int cargaHoraria;
   
   public int getCargaHoraria(){
      return cargaHoraria;
   }
   
   public void setCargaHoraria(int cargaHoraria){
      this.cargaHoraria = cargaHoraria;
   }
   
   public ProfessorHorista(String nome, Documento documento, Data nascimento, String conjuge, Documento carteiraDeTrabalho, double salario, int cargaHoraria){
      super(nome, documento, nascimento, conjuge, carteiraDeTrabalho, salario);
      this.cargaHoraria = cargaHoraria;
   } 
   
   public ProfessorHorista(String nome, Documento documento, Data nascimento, Documento carteiraDeTrabalho, double salario, int cargaHoraria){
      super(nome, documento, nascimento, carteiraDeTrabalho, salario);
      this.cargaHoraria = cargaHoraria;
   }
   
   public double getSalario(){
      return super.getSalario() + 20*cargaHoraria;
   }
   
   public String toString(){
      return super.toString() + "\nCarga Horaria: " + cargaHoraria + " aulas.";
   }
   
}