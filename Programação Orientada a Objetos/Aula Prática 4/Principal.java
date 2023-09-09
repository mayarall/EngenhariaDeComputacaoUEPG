public class Principal{

   public static void main(String args[]){
      
      Produto vetor[] = new Produto[2];
      Data d1 = new Data(13, 9, 2021);
      Data d2 = new Data(24, 10);
      
      vetor[0] = new Produto("Leite de Soja", 20, 6.5, d1);
      vetor[1] = new Produto("Leite de Amendoas", 15.5, d2);
      
      vetor[0].imprimir();
      vetor[1].imprimir();
      
      vetor[0].vender(2);
      vetor[1].vender(5);
      
      vetor[1].comprar(30);
      
      vetor[0].imprimir();
      vetor[1].imprimir();
   }

}