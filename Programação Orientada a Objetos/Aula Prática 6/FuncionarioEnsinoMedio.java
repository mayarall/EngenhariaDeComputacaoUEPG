public class FuncionarioEnsinoMedio extends Funcionario{

   private String nomeEscola;
   
   public FuncionarioEnsinoMedio(String nome, String telefone, Data nascimento, String registro, double salario, String nomeEscola){
      super(nome, telefone, nascimento, registro, salario);
      this.nomeEscola = nomeEscola;
   }
   
   public double getSalarioComAdicional(){
      return getSalario()*1.1;
   }
   
   public String toString(){
      return super.toString() + "Nome da escola: " + nomeEscola;
   }

}