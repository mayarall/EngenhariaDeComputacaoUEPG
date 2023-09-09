public class AlunoPos extends Aluno{
   public AlunoPos(String nome, String telefone, Data nascimento, String ra){
      super(nome, telefone, nascimento, ra);
   }
   
   @Override
   public double getCargaSemanal(){
      return 2 * getDisciplinas();
   }

}