import javax.swing.JOptionPane;

public class EntradaSaida{
   public static void main(String args[]){
      JOptionPane.showMessageDialog(null, "Digite um inteiro!");  
      String valor = JOptionPane.showInputDialog(null, "Qual o inteiro? ");
      if(valor == null)
         return;
      int num = Integer.parseInt(valor);
      JOptionPane.showMessageDialog(null, "O dobro e : "+(2*num));  
   }
}