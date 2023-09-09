import java.util.Arrays;

public class Vetor{
   
   public static int somaValores(int vetor[]){
      int soma = 0;
      
      for(int i=0; i<vetor.length; i++){
         soma = soma + vetor[i];
      }
          
      return soma;
   }
   
   public static float mediaAritmetica(int vetor[]){
      
      return (float) somaValores(vetor) / vetor.length;      
   }
   
   public static void imprimir(int vetor[]){
   
      System.out.println("Vetor:");
      
      for(int i=0; i<vetor.length; i++){
         System.out.print(vetor[i] + " ");
      }
      
      System.out.println(" ");
   }
   
   public static void ordenar(int vetor[]){
      Arrays.sort(vetor);
   }
   
   public static void pesquisaBinaria(int vetor[], int chave){
      
      int resposta;
      ordenar(vetor);
      resposta = Arrays.binarySearch(vetor, chave);
      
      if(resposta >= 0)
         System.out.println("\nValor " + chave + " encontrado na posicao " + resposta);
      else System.out.println("\nValor nao encontrado! " + resposta);
      
      
   }
   
}