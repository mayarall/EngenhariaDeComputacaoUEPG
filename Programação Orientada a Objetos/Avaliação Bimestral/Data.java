import java.text.DateFormat;
import java.util.Calendar;

public class Data{
   
   private int dia;
   private int mes;
   private int ano;
   
   public void setDia(int dia){
      if(dia <= 31 && dia >= 1){
         this.dia = dia;
         System.out.println("Dia " + dia + " inserido com sucesso.");
      }else
         System.out.println("O numero inserido eh invalido.");
   }
   
   public int getDia(){
      return dia;
   }
   
   public void setMes(int mes){
      if(mes <= 12 && mes >= 1){
         this.mes = mes;
         System.out.println("Mes " + mes + " inserido com sucesso.");
      }else
         System.out.println("O numero inserido eh invalido.");
   }
   
   public int getMes(){
      return mes;
   }
   
   
   public void setAno(int ano){
      if(ano <= 202 && ano >= 1900){
         this.ano = ano;
         System.out.println("Ano " + ano + " inserido com sucesso.");
      }else
         System.out.println("O numero inserido eh invalido.");
   }
   
   public int getAno(){
      return ano;
   }
   
   public String toString(){
      return dia+"/"+mes+"/"+ano;
   }
   
   public Data(int dia, int mes, int ano){
      this.dia = dia;
      this.mes = mes;
      this.ano = ano;
   }
   
   static void retornarDataAtual(){
      Calendar cal = Calendar.getInstance();
      DateFormat f = DateFormat.getDateInstance();
      System.out.println("Data e Hora atual: " + f.format(cal.getTime()));
   }
}