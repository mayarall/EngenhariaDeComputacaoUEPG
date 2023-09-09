public class ProfessorDedicacaoExclusiva extends Funcionario{
   
   public ProfessorDedicacaoExclusiva(String nome, Documento documento, Data nascimento, String conjuge, Documento carteiraDeTrabalho, double salario ){
      super(nome, documento, nascimento, conjuge, carteiraDeTrabalho, salario);
   }
   
   public ProfessorDedicacaoExclusiva(String nome, Documento documento, Data nascimento, Documento carteiraDeTrabalho, double salario){
      super(nome, documento, nascimento, carteiraDeTrabalho, salario);
   }
   
   public double getSalario(){
      return super.getSalario()*1.55;
   }
   
   public String toString(){
      return super.toString();
   }
}