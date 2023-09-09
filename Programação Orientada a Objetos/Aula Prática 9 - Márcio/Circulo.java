public class Circulo implements FiguraGeometrica, FiguraEscalavel{
   private double raio;
   
   public Circulo(double raio){
      this.raio = raio;
   }
   
   public double calcularArea(){
      return Math.PI*raio*raio;
   }
   
   public double calcularPerimetro(){
      return 2*Math.PI*raio;
   }
   
   public void diminuirFigura(double numero){
      raio -= numero;
   }
   
   public void aumentarFigura(double numero){
      raio += numero;
   }  
   
   public String toString(){
      return "Sou um circulo de raio: " + raio;
   }
}