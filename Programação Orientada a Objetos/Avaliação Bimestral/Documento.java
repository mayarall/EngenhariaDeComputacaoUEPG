public class Documento{
   private String tipo;
   private Data emissao;
   private String numero;
   
   public String getTipo(){
      return tipo;
   }
   
   public void setTipo(String tipo){
      if(tipo != "")
         this.tipo = tipo;
   }
   
   public String getNumero(){
      return numero;
   }
   
   public void setNumero(String numero){
      if(numero != "")
         this.numero = numero;
   }
   
   public void setEmissao(Data emissao){
      this.emissao = emissao;
   }
   
   public String toString(){
      return tipo + " - Numero: " + numero + " - Data de Emissao: " + emissao; 
   }
   
   public Documento(String tipo, Data emissao, String numero){
      this.tipo = tipo;
      this.emissao = emissao;
      this.numero = numero;
   }
}