#include <iostream>
#include <cassert>

using namespace std;

template <typename T>

class Vector{
			private:
					T *storage;
					int sz=0;
					int capacity;

			public:
					//Constructor.
					Vector(){
							storage=new T[5];
							sz;
							capacity=5;}

					//Me permite añadir elementos al vector desde el final.
					void push_back(const T &elem){
									if(sz==capacity){resize();}
									storage[sz]=elem;
									sz++;}

			private:
					//Agrandar tamaño.
					void resize(){
								T *newstorage=new T[capacity*2];
								for(int i=0;i<sz;i++){
									newstorage[i]=storage[i];}
								delete[]storage;
								storage=newstorage;
								capacity=capacity*2;}

			public:
					//Me da el tamaño.
					int size()const{return sz;}

					//Devuelve una referencia y me da el elemento que hay en la posición tal.
					T& at(int p)const{
									assert(p>=0&&p<sz);{return storage[p];}
									}
			};

int main(){
			//Creo el objeto de la clase Vector
			Vector<int> edades;

			//Le agrego datos.
			edades.push_back(18);
			edades.push_back(20);
			edades.push_back(30);
			edades.push_back(17);
			edades.push_back(90);
			edades.push_back(8);

			//Pregunto por su tamaño.
			int x=edades.size();
			cout<<x<<endl;

			//Pregunto por lo que hay en x posición.
			int e=edades.at(4);
			cout<<e;

			return 0;}
