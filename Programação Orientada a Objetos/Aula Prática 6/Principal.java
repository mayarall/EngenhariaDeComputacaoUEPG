public class Principal{
   public static void main(String args[]){
      
      Data d = new Data(27,11,2000);
      Aluno a1 = new Aluno("Mayara", "42988003205", d, "19008226");
      Aluno a2 = new AlunoPos("Fulano", "40028922", d, "12345678" );
      
      a1.matricular(6);
      a2.matricular(6);
      
      System.out.println("\nCarga horaria do aluno da graduacao: " + a1.getCargaSemanal() + " horas");
      System.out.println("\nCarga horaria do aluno da pos graduacao: " + a2.getCargaSemanal() + " horas");
   
      Funcionario f1 = new Funcionario("Sicrano", "42988003205", d, "001", 1500);
      Funcionario f2 = new FuncionarioEnsinoMedio("Beltrano", "42988003205", d, "001", 1500, "Escolinha");
      Funcionario f3 = new FuncionarioGraduacao("Maria", "42988003205", d, "001", 1500, "Escola", "Computacao");
   
      System.out.printf("\n\nFuncionario sem estudo: \nSem adicional: %.2f \nCom adicional: %.2f",  f1.getSalario(), f1.getSalarioComAdicional());
      System.out.printf("\n\nFuncionario com ensino medio: \nSem adicional: %.2f \nCom adicional: %.2f",  f2.getSalario(), f2.getSalarioComAdicional());
      System.out.printf("\n\nFuncionario com graduacao: \nSem adicional: %.2f \nCom adicional: %.2f",  f3.getSalario(), f3.getSalarioComAdicional());   
   
   }
}