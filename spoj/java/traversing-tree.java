import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;


//public class Treverse {
public class Main {	
    public static void main(String[] args) throws IOException {
            BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter w = new BufferedWriter(new OutputStreamWriter(System.out));
            StringTokenizer st;		 
            
            Integer n = Integer.parseInt(r.readLine());
            
            st = new StringTokenizer(r.readLine());
            
            ArbolBinarioDeBusqueda<Integer> tree = new ArbolBinarioDeBusqueda<Integer>(Integer.parseInt(st.nextToken()));
            
            for(int i = 1; i < n; i++) {
                tree.agregarModificado(Integer.parseInt(st.nextToken()));
            }
            
            w.write("Pre order : " + tree.preOrder() + "\n");
            w.write("In order  : " + tree.inOrder() + "\n");
            w.write("Post order: " + tree.postOrder() + "\n");
            
            w.flush();
    }
}
    
class NodoBinario<T extends Comparable<T>> {
    
    private T dato;
    private NodoBinario<T> hijoIzquierdo;
    private NodoBinario<T> hijoDerecho;
    
    public NodoBinario(T dato){		
        this.dato = dato;
        this.hijoIzquierdo = null;
        this.hijoDerecho = null;
    }
    
    public T getDato(){		
        return this.dato; 
    }
    
    public NodoBinario<T> getHijoIzquierdo(){		
        return this.hijoIzquierdo;
    }
    
    public NodoBinario<T> getHijoDerecho(){		
        return this.hijoDerecho;
    }	
    
    public void setDato(T dato){		
        this.dato = dato;
    }
    
    public void setHijoIzquierdo(NodoBinario<T> hijoIzq){		
        this.hijoIzquierdo = hijoIzq;
    }
    
    public void setHijoDerecho(NodoBinario<T> hijoDer){		
        this.hijoDerecho = hijoDer;
    }	
}
    
class ArbolBinarioDeBusqueda<T extends Comparable<T>> {
    
    private NodoBinario<T> raiz;
    
    public ArbolBinarioDeBusqueda(T dato) {
        this.raiz = new NodoBinario<T>(dato);
    }
    
    private ArbolBinarioDeBusqueda(NodoBinario<T> nodo) {
        this.raiz = nodo;
    }
    
    private NodoBinario<T> getRaiz() {
        return raiz;
    }
    
    public T getDatoRaiz() {
        if (this.getRaiz() != null) {
            return this.getRaiz().getDato();
        } else {
            return null;
        }
    }
    
    public ArbolBinarioDeBusqueda<T> getHijoIzquierdo() {
        return new ArbolBinarioDeBusqueda<T>(this.raiz.getHijoIzquierdo());
    }
    
    public ArbolBinarioDeBusqueda<T> getHijoDerecho() {
        return new ArbolBinarioDeBusqueda<T>(this.raiz.getHijoDerecho());
    }
    
    private NodoBinario<T> buscar(Comparable<T> x, NodoBinario<T> t) {
        if (t != null) {
            if (x.compareTo(t.getDato()) < 0) {
                t = this.buscar(x, t.getHijoIzquierdo());
            } else if (x.compareTo(t.getDato()) > 0) {
                t = this.buscar(x, t.getHijoDerecho());
            } else
                ; // Se encontro el nodo, asi que es t
            return t;
        } else {
            return null;
        }
    }
    
    public boolean incluye(Comparable<T> dato) {
        return buscar(dato, this.raiz) != null;
    }
    
    public T buscar(T dato) {
        NodoBinario<T> result = this.buscar(dato, this.getRaiz());
        if (result != null) {
            return result.getDato();
        }
        return null;
    }
    
    public void eliminar(T dato) {
        this.raiz = this.eliminar(dato, raiz);
    }
    
    private NodoBinario<T> eliminar(T dato, NodoBinario<T> t) {
        if (t.getDato().compareTo(dato) > 0) {
            if (t.getHijoIzquierdo() != null)
                t.setHijoIzquierdo(this.eliminar(dato, t.getHijoIzquierdo()));
        } else if (t.getDato().compareTo(dato) < 0) {
            if (t.getHijoDerecho() != null)
                t.setHijoDerecho(this.eliminar(dato, t.getHijoDerecho()));
        } else if (t.getDato().compareTo(dato) == 0) {
            if (t.getHijoIzquierdo() != null && t.getHijoDerecho() != null) {
                NodoBinario<T> menor = this.buscarMayorDeLosMenores(t);
                t.setDato(menor.getDato());
                t.setHijoIzquierdo(this.eliminar(menor.getDato(), t.getHijoIzquierdo()));
            } else {
                // tiene un solo hijo o es hoja
                if (t.getHijoIzquierdo() != null)
                    t = t.getHijoIzquierdo();
                else
                    t = t.getHijoDerecho();
            }
        }
        return t;
    }
    
    private NodoBinario<T> buscarMayorDeLosMenores(NodoBinario<T> t) {
        if (t.getHijoIzquierdo()!=null){
            NodoBinario<T> maxDerecho = t.getHijoIzquierdo();
            while (maxDerecho.getHijoDerecho()!=null){
                maxDerecho=maxDerecho.getHijoDerecho();
            }
            return maxDerecho;
        }
        return t;
    }
    
    public boolean esVacio() {
        return (this.getRaiz() == null);
    }
    
    public boolean esHoja() {
        return this.getDatoRaiz() != null && this.getHijoIzquierdo().esVacio() && this.getHijoDerecho().esVacio();
    }
    
    public void imprimirInOrden() {
        if (this.esVacio())
            System.out.println("Arbol Vacio");
        else
            imprimirInOrden(this.raiz);
    }
    
    private void imprimirInOrden(NodoBinario<T> t) {
        if (t != null) {
            imprimirInOrden(t.getHijoIzquierdo());
            System.out.println(t.getDato());
            imprimirInOrden(t.getHijoDerecho());
        }
    }
    
    public String preOrder() {
        String result = this.getDatoRaiz().toString();
        
        if(!this.getHijoIzquierdo().esVacio()) {
            result += " " + this.getHijoIzquierdo().preOrder();
        }
        
        if(!this.getHijoDerecho().esVacio()) {
            result += " " + this.getHijoDerecho().preOrder();
        }
        
        return result;
    }
    
    public String inOrder() {
        String result = "";
        
        if(!this.getHijoIzquierdo().esVacio()) {
            result += this.getHijoIzquierdo().inOrder() + " ";
        }
        
        result += this.getDatoRaiz().toString();
        
        if(!this.getHijoDerecho().esVacio()) {
            result += " " + this.getHijoDerecho().inOrder(); 
        }
        
        return result;
    }
    
    public String postOrder() {
        String result = "";
        
        if(!this.getHijoIzquierdo().esVacio()) {
            result += this.getHijoIzquierdo().postOrder() + " ";
        }
        
        if(!this.getHijoDerecho().esVacio()) {
            result += this.getHijoDerecho().postOrder() + " ";
        }
        
        result += this.getDatoRaiz().toString();
        
        return result;
    }
    
    
    public void agregarModificado(T dato) {
        //como el agregar pero tambien agrega los iguales a la derecha
        if (raiz == null)
            raiz = new NodoBinario<T>(dato);
        else
            this.agregarModificado(dato, raiz);
    }
    
    private void agregarModificado(T dato, NodoBinario<T> r){
        if (dato.compareTo(r.getDato()) < 0)
            if (r.getHijoIzquierdo() == null)
                r.setHijoIzquierdo(new NodoBinario<T>(dato));
            else
                this.agregarModificado(dato, r.getHijoIzquierdo());
        else {
            //si es igual tambien lo agrego para la derecha
            if (r.getHijoDerecho() == null)
                r.setHijoDerecho(new NodoBinario<T>(dato));
            else
                this.agregarModificado(dato, r.getHijoDerecho());
        }
    }
    
    public void agregar(T dato) {
        if (raiz == null)
            raiz = new NodoBinario<T>(dato);
        else
            this.agregar(dato, raiz);
    }
    
    private void agregar(T dato, NodoBinario<T> r) {
        if (dato.compareTo(r.getDato()) < 0)
            if (r.getHijoIzquierdo() == null)
                r.setHijoIzquierdo(new NodoBinario<T>(dato));
            else
                this.agregar(dato, r.getHijoIzquierdo());
        else if (dato.compareTo(r.getDato()) > 0)
            if (r.getHijoDerecho() == null)
                r.setHijoDerecho(new NodoBinario<T>(dato));
            else
                this.agregar(dato, r.getHijoDerecho());
    }
    
} 