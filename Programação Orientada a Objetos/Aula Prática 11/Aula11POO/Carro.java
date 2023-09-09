package Aula11POO;

public class Carro {
    
    private String modelo;
    private int potencia;
    
    public void setModelo(String modelo){
        this.modelo = modelo;
    }
    
    public void setPotencia(int potencia){
        this.potencia = potencia;
    }
    
    @Override
    public String toString(){
        return "Sou um carro do modelo " + modelo + " com potencia " + potencia;
    }
}
