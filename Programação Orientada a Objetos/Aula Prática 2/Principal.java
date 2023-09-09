public class Principal{
   public static void main(String args[]){
   
      Produto produto[];
      
      produto = new Produto[4]; 
      
      produto[0] = new Produto("Notebook", 3000.00, 50);
      produto[1] = new Produto("Smartphone", 1000.00);
      produto[2] = new Produto("Tablet", 1500.00);
      produto[3] = new Produto(produto[2].getNome(), produto[1].getPreco(), produto[0].getQuantidade());
      
      produto[1].setQuantidade(produto[0].getQuantidade());
      produto[1].setPreco(1800.00);
      produto[2].setQuantidade(30);
      produto[2].setNome("Headset");
      
      produto[0].vender(10);
      produto[1].comprar(20);
      
      produto[2].imprimir();
      System.out.println(produto[3]);
      
   
   }
}