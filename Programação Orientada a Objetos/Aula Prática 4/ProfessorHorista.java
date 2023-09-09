public class ProfessorHorista extends Funcionario{
   private int aulas;
   
   public ProfessorHorista(String nome, Documento documento, Data nascimento, String conjuge, Documento carteiraDeTrabalho, double salario, int aulas){
      super(nome, documento, nascimento, conjuge, carteiraDeTrabalho, salario);
      this.aulas = aulas;
   } 
}