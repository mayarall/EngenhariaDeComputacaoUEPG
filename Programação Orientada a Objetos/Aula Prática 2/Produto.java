public class Produto{
   private String nome;
   private double preco;
   private int quantidade;
   
   public void setNome(String nome){
      this.nome = nome;
   }
   public String getNome(){
      return nome;
   }
   
   public void setPreco(double preco){
      if(preco > 0)
         this.preco = preco;
      else
         System.out.println("Valor invalido.\n");
   }
   public double getPreco(){
      return preco;
   }
   
   public void setQuantidade(int quantidade){
      if(quantidade >= 0)
         this.quantidade = quantidade;
      else
         System.out.println("Valor invalido.\n");
   }
   public int getQuantidade(){
      return quantidade;
   }
   
   public String toString(){
      String retorno;
      retorno = "Nome: " + nome + "\nPreço: " + preco + "\nQuantidade: " + quantidade;
      return retorno;
   }
   
   public Produto(String nome, double preco, int quantidade){
      this.nome = nome;
      this.preco = preco;
      this.quantidade = quantidade;
   }
   
   public Produto(String nome, double preco){
      this.nome = nome;
      this.preco = preco;
   }
   
   public void vender(int qtde){
      if(qtde <= quantidade){
            quantidade = quantidade - qtde;
            System.out.println("Venda de " + qtde + " " + this.nome + "(s) realizada com sucesso!\n");
         }else
        System.out.println("Nao ha produtos suficientes no estoque.\n");
   }
   
   public void comprar(int qtde){
      if(qtde > 0){
         quantidade = quantidade + qtde;
         System.out.println("Compra de " + qtde + " " + this.nome+ "(s) realizada com sucesso!\n");
      
      }else
         System.out.println("Quantidade de produtos invalida.\n");
   }
   
   public void imprimir(){
      System.out.println("Nome: " + nome);
      System.out.println("Preco: " + preco);
      System.out.println("Quantidade: " + quantidade + "\n");
   }
}