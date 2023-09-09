public abstract class Quadrilatero implements FiguraGeometrica, FiguraEscalavel{
   private double ladoA, ladoB, ladoC, ladoD;
   
   public Quadrilatero(double ladoA, double ladoB, double ladoC, double ladoD){
      this.ladoA = ladoA;
      this.ladoB = ladoB;
      this.ladoC = ladoC;
      this.ladoD = ladoD;
   }

   public double getLadoA(){
      return ladoA;
   }
   
   public double getLadoB(){
      return ladoB;
   }
   
   public double getLadoC(){
      return ladoC;
   }
   
   public double getLadoD(){
      return ladoD;
   }
   
   public double calcularPerimetro(){
      return ladoA + ladoB + ladoC + ladoD;
   }
   
    public void aumentarFigura(double numero){
      ladoA = ladoA + numero;
      ladoB = ladoB + numero;
      ladoC = ladoC + numero;
      ladoD = ladoD + numero;
   }
   
   public void diminuirFigura(double numero){
      ladoA = ladoA - numero;
      ladoB = ladoB - numero;
      ladoC = ladoC - numero;
      ladoD = ladoD - numero;
   }
   
   public String toString(){
      return "Sou um quadrilatero de lados: " + ladoA + ", " + ladoB + ", " + ladoC + ", " + ladoD ;
   } 
}  