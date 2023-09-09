public class FuncionarioGraduacao extends FuncionarioEnsinoMedio{
   private String curso;
   
   public FuncionarioGraduacao(String nome, String telefone, Data nascimento, String registro, double salario, String nomeEscola, String curso){
      super(nome, telefone, nascimento, registro, salario, nomeEscola);
      this.curso = curso;
   }
   
   @Override
   public double getSalarioComAdicional(){
      return super.getSalarioComAdicional()*1.5;
   }
   
   public String toString(){
      return super.toString() + "\nCurso " + curso;
   }
}