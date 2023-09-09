public class Pessoa{
   private String nome;
   private Documento documento;
   private Data nascimento;
   private String conjuge;
   
   public String getNome(){
      return nome;
   }
   
   public void setNome(String nome){
      if(nome != "")
         this.nome = nome;
   }
   
   public String getConjuge(){
      return conjuge;
   }
   
   public void setConjuge(String conjuge){
      if(conjuge != "")
         this.conjuge = conjuge;
   }
   
   public void setDocumento(Documento documento){
      this.documento = documento;
   }
   
   public void setNascimento(Data nascimento){
      this.nascimento = nascimento;
   }
   
   public String toString(){
      String retorno = "Nome: " + nome + "\nData de Nascimento: " + nascimento + "\nDocumento: " + documento;
      
      if(conjuge != null)
        retorno = retorno + "\nConjuge: " + conjuge;
      
      return retorno;
      
   }
   
   public Pessoa(String nome, Documento documento, Data nascimento, String conjuge){
      this.nome = nome;
      this.documento = documento;
      this.nascimento = nascimento;
      this.conjuge = conjuge;
   }
   
   public Pessoa(String nome, Documento documento, Data nascimento){
      this.nome = nome;
      this.documento = documento;
      this.nascimento = nascimento;
   }
   
   public void editar(String nome, Data nascimento){
      this.nome = nome;
      this.nascimento = nascimento;
   }
   
   public void editar(Documento documento, String conjuge){
      this.documento = documento;
      this.conjuge = conjuge;
   }
}