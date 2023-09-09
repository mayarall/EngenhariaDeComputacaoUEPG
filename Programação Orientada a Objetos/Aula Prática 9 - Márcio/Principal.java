public class Principal{
   public static void main(String args[]){
   
      FiguraGeometrica vetor[] = new FiguraGeometrica[3];
      FiguraEscalavel temp;
      
      vetor[0] = new Quadrado(4);
      vetor[1] = new Retangulo(4, 2);
      vetor[2] = new Circulo(3);
      
      for(int i=0; i<3; i++){
         temp = (FiguraEscalavel) vetor[i];
         temp.diminuirFigura(1);
         System.out.println(vetor[i]);
         System.out.printf("Minha area e: %.2f", vetor[i].calcularArea());
         System.out.printf("\nMeu perimetro e: %.2f\n\n", vetor[i].calcularPerimetro());
         
      }
      
   }
}