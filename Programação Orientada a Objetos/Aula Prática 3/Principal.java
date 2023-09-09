public class Principal{
   
   public static void main(String args[]){
   
      int vetor1[] = {1, 2, 3, 4, 5, 6};
      int vetor2[] = {10, 20, 34};
      int vetor3[] = {500, 400, 200};
      
      System.out.println("\nA soma dos valores do vetor 1 eh : " + Vetor.somaValores(vetor1) + "\n");
      
      System.out.printf("A media aritmetica dos valores do vetor 2 eh : %.2f \n", Vetor.mediaAritmetica(vetor2));
      
      Vetor.ordenar(vetor3);
      System.out.println("\nO vetor 3 foi ordenado!");
      Vetor.imprimir(vetor3);
      
      Vetor.pesquisaBinaria(vetor1, 4);
         
   }
   
}