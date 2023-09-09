public class Aluno extends Pessoa{
   private String ra;
   private int disciplinas;
   private boolean matricula;

   public Aluno(String nome, String telefone, Data nascimento, String ra){
      super(nome, telefone, nascimento);
      this.ra = ra;
   }
   
   public Aluno(String nome, Data nascimento, String ra){
      super(nome, nascimento);
      this.ra = ra;   
   }
   
   public void setRa(String ra){
      this.ra = ra;
   }
   
   public String getRa(){
      return ra;
   }
   
   public void setDisciplinas(int disciplinas){
      this.disciplinas = disciplinas;
   }
   
   public int getDisciplinas(){
      return disciplinas;
   }
   
   public String toString(){
      String retorno;
      retorno = super.toString() + "\nRA: " + ra + "\nDisciplinas: " + disciplinas;
      if(matricula)
         retorno = retorno + "\nAluno matriculado";
      else 
         retorno = retorno + "\nAluno nao matriculado";
      
      return retorno;
   }
   
   public void matricular(int disciplinas){
      matricula = true;
      this.disciplinas = disciplinas;
   }
   
   public double getCargaSemanal(){
      return 4 * disciplinas;
   }
   
}