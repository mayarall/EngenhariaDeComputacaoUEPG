public class Produto{
   private String nome;
   private double preco;
   private int quantidade;
   private Data validade;
   
   public void setNome(String nome){
      this.nome = nome;
   }
   public String getNome(){
      return nome;
   }
   
   public void setPreco(double preco){
      if(preco >= 0)
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
   
   public void setValidade(int dia, int mes, int ano){
      validade.setDia(dia);
      validade.setMes(mes);
      validade.setAno(ano);
   }
   
   public void setValidade(Data data){
      this.validade = data;
   }
   
   public String toString(){
      String retorno;
      retorno = "Nome: " + nome + "\nPreço: " + preco + "\nQuantidade: " + quantidade + "\nValidade: " + validade;
      return retorno;
   }
   
   public Produto(String nome, int quantidade, double preco, Data validade){
      this.nome = nome;
      this.quantidade = quantidade;
      this.preco = preco;
      this.validade = validade;
   }
   
   public Produto(String nome, double preco, Data validade){
      this.nome = nome;
      this.preco = preco;
      this.validade = validade;
   }
   
   public Produto(String nome, Data validade){
      this.nome = nome;
      this.validade = validade;
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
      System.out.println("Validade: " + validade);
      System.out.println("Quantidade: " + quantidade + "\n");
   }
}