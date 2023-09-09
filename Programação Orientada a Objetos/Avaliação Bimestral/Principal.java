public class Principal{
   public static void main(String args[]){
      
      Data dataRG = new Data(2, 9, 2000);
      Data dataCarteira = new Data(9, 11, 2010);
      Data nascimento = new Data(10, 10, 1980);
      
      Documento rg = new Documento("RG", dataRG, "12345678-9");
      Documento carteira = new Documento("Carteira de Trabalho", dataCarteira, "12345");
      
      //Criando um Funcionário e mostrando as suas informações:
      
      Funcionario maria = new Funcionario("Maria", rg, nascimento, "Carlos", carteira, 1000.00);
      
      System.out.println(maria + "\n");
      
      //Criando os professores e mostrando suas informações:
      
      ProfessorHorista cleber = new ProfessorHorista("Cleber", rg, nascimento, carteira, 1000, 25);
      System.out.println(cleber + "\n");
       
      ProfessorDedicacaoExclusiva p[] = new ProfessorDedicacaoExclusiva[2];
      p[0] = new ProfessorDedicacaoExclusiva("Daniel", rg, nascimento, "Felipe", carteira, 1000.00);
      p[1] = new ProfessorDedicacaoExclusiva("Joana", rg, nascimento, carteira, 2000.00);
      
      System.out.println(p[0] + "\n\n" + p[1] + "\n");
      
   }
}