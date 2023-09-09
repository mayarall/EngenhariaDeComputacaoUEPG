package Aula11POO;

import java.util.InputMismatchException;
import java.util.Scanner;

public class Principal {
    public static void main(String args[]){
        
        Scanner le = new Scanner(System.in);
        
        Carro carro[] = new Carro[2];
        boolean certo = false;
        int indice;
        String entrada;
        
        do{
            try{
                System.out.println("Digite um indice: ");
                indice = le.nextInt();
                carro[indice] = new Carro();
                
                System.out.println("Digite o modelo do carro: ");
                entrada = le.next();
                carro[indice].setModelo(entrada);
                
                System.out.println("Digite a potencia do carro: ");
                entrada = le.next();
                carro[indice].setPotencia(Integer.parseInt(entrada));
                
                certo = true;
                
            }catch(InputMismatchException ex){
                System.out.println("Voce deve digitar um inteiro.");
                le.next();
            }
        }while(!certo);
        
        
        //carro[0].setModelo("Volkswagen Gol 1.6");
        //carro[0].setPotencia(104);
        
      
      
      System.out.println(carro[indice]);
      
    }
}
