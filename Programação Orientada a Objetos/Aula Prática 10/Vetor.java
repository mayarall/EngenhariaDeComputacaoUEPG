package br.uepg.deinfo.primeiro;
import javax.swing.JOptionPane;

public class Vetor{

   private Pessoa vetor[];
   private int posicao;
   
   public Vetor(int tam){
      vetor = new Pessoa[tam];
   }
   
   public void adicionar(){
      String nome, valor;
      double salario;
      int codigo;
      
      JOptionPane.showMessageDialog(null, "Digite as informações da pessoa!");  
      nome = JOptionPane.showInputDialog(null, "Qual o nome? ");
      if(nome == null)
         return;
         
      valor = JOptionPane.showInputDialog(null, "Qual o código? ");
      if(valor == null)
         return;
      codigo = Integer.parseInt(valor);
      
      valor = JOptionPane.showInputDialog(null, "Qual o salário? ");
      if(valor == null)
         return;
      salario = Double.parseDouble(valor);
      
      vetor[posicao] = new Pessoa(codigo, nome);
      vetor[posicao].salario = salario;
      posicao++;      
   }
   
   public void imprimir(int pos){
      if(pos < 0 || pos >= posicao)
         System.out.println("Posicao invalida");
      else JOptionPane.showMessageDialog(null, vetor[pos]);
   }
      
}