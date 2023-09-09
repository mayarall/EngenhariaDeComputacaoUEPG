package br.uepg.deinfo.primeiro;
   
public class Pessoa{
   protected double salario;
   private int codigo;
   private String nome;
   
   protected Pessoa(int codigo, String nome){
      this.codigo = codigo;
      this.nome = nome;
   }   
   
   protected int getCodigo(){
      return codigo;
   }
   
   protected String getNome(){
      return nome;
   }
   
   public String ToString(){
      return "Nome: "+ nome + "\nCodigo: " + codigo + "\nSalario: " + salario;
   }  
}