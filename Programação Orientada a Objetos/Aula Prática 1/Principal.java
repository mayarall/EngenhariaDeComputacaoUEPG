public class Principal{
   public static void main(String args[]){
      Produto produto1, produto2, produto3;
      
      produto1 = new Produto();
      produto1.setNome("Notebook");
      produto1.setPreco(3000.00);
      produto1.setQuantidade(50);
      produto1.imprimir();
      
      produto2 = new Produto();
      produto2.setNome("Smartphone");
      produto2.setPreco(1000.00);
      produto2.setQuantidade(45);
      produto2.imprimir();
      
      produto3 = new Produto();
      produto3.setNome(produto1.getNome());
      produto3.setPreco(produto2.getPreco());
      produto3.setQuantidade(produto1.getQuantidade());
      produto3.imprimir();
   
   }
}