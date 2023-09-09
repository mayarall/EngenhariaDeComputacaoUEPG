public class Principal{
   public static void main(String args[]){
   
      Data d = new Data(27,11,2000);
      Data d1 = new Data(18, 6, 1995);
      Data d2 = new Data(12,9,1976);
      Data d3 = new Data(12,9, 1978);
      
      Aluno aluno[] = new Aluno[2];
      aluno[0] = new Aluno("Adalberto", "1234-5678", d, "19008226");
      aluno[1] = new Aluno("Jurema", d1, "19008526");
      
      Funcionario funcionario[] = new Funcionario[2];
      funcionario[0] = new Funcionario("Pedro", "4002-8922", d2, "1010", 2000);
      funcionario[1] = new Funcionario("Joana", d3, "1011", 2000);
      
      System.out.println(aluno[0]);
      System.out.println(aluno[1]);
      System.out.println(funcionario[0]);
      System.out.println(funcionario[1]);
   }
}