public class Quadrado extends Quadrilatero{
   public Quadrado(double lado){
      super(lado, lado, lado, lado);
   }
   
   public double calcularArea(){
      return getLadoA()*getLadoA();
   }
   
}