//                                           امجد عبد االخالق احمد الصيفى 12135 

#include<iostream>
#include<string>
#include<math.h>
using namespace std;




class point {
	float x , y;
	 string  name ; 
public: 
	void set_point (float xcoord , float ycoord ){  x=xcoord ;    y=ycoord;     }

	float get_x () { return  x; }
	 
	void set_x(float xcoord) { x=xcoord; }
	  
	float get_y() { return y; } 

	void set_y(float ycoord ) { y=ycoord; }

	void print_point () { 		cout<<"("<<x<<","<<y<<")";     }
	
	void print_comma_point() {        cout<<"("<<x<<","<<y<<")"<<",";    }

	void move(float dx , float dy )  { x=x+dx ;        y=y+dy;   }

	void set_name (string h ) { name =h; }

	string get_name ()  { return name ;  }



	void read_point (string a ) { //(123,23)
		int s=a.find(",");
		int e=a.find(")");
		float x=atof(a.substr(1,s-1).c_str());
		float y=atof(a.substr(s+1,e-s-1).c_str());
		set_point(x,y);
	}
	
	bool is_equal (point o){
		if (x==o.get_x() && y==o.get_y()) 
			return 1 ;
		else return 0;
	} 





	
	point()
	{
		x=0;
		y=0;
	}


	point(float x , float y) {
		set_x(x);  
	set_y(y); 
	}



};

//........................................................................................................................................

float slope ( point p1 , point p2);
float dis(point p1 , point p2 );


class polygon {
private:
     point pa[100];
	int no_point ;
	
public:
	void set_polygon_point( float x ,float y , int index ){	
		point a ; 
		a.set_x(x);
		a.set_y(y);
		pa[index]=a; 
	}

	void set_no_point (int no ){     no_point=no	;   }
	 
	int get_no_point () { return no_point ;  }

	point get_polygon_point (int index ) { return pa[index];  }

	float  get_polygon_point_x (int index) { 
	point a = pa[index];
	return a.get_x();
	}

	float  get_polygon_point_y (int index){
		point a = pa[index];
	return a.get_y();
	}

	void print_one_point_of_polygon(int index_in_pa){
		if(index_in_pa == get_no_point()-1) 

			pa[index_in_pa].print_point();

		else pa[index_in_pa].print_comma_point();
	}




	void print_polygon_point (){
		for (int i=0; i<get_no_point()-1 ; i++ ){
			  pa[i].print_comma_point();
	}
		            pa[get_no_point()-1].print_point();
	}





	polygon() {
		no_point =0;
	}
	//....................................................................................................................................................................
	

	bool is_identical( int index_in_pa ){
	point a = get_polygon_point(index_in_pa);
	int u=0;
	
//                               NOT FIRST , NOT LAST 
	if (index_in_pa !=0 )	 {
		point a0 = get_polygon_point(index_in_pa-1); 
		if(  a.get_x() == a0.get_x()  &&  a.get_y() == a0.get_y() )
			u=1;             }

	//                                                FIRST                                      
	if(index_in_pa==0)	{	
		point a0 =get_polygon_point(get_no_point()-1);   
		if(  a.get_x() == a0.get_x()  &&  a.get_y() == a0.get_y() )
			u=1;             }
	
	 
	return u;
	}










//.......................................................IS RED.........................................................................



	bool is_red ( int index_in_pa ){
	point a = get_polygon_point(index_in_pa);
	int u=0;
	
//..........................NOT FIRST , NOT LAST (3CASES).....................................................
	if (index_in_pa !=0 && index_in_pa != get_no_point()-1){

	point a0 = get_polygon_point(index_in_pa-1);
	point a1 = get_polygon_point(index_in_pa+1);

	
		if(a.get_x() != a0.get_x() && a.get_x() != a1.get_x() &&    a.get_y() != a0.get_y() && a.get_y() != a1.get_y()    ){
			if (slope(a,a0)==slope(a,a1))         u=1;	  //slope not 0 not oo   (inclined)
		}
     if(  ( a.get_x() == a0.get_x() && a.get_x() == a1.get_x() ) && ( a.get_y() != a0.get_y() && a.get_y() != a1.get_y()  )  ) 
	       u=1;   //slope=oo   (vertical)



		 if(  ( a.get_x() != a0.get_x() && a.get_x() != a1.get_x() ) && ( a.get_y() == a0.get_y() && a.get_y() == a1.get_y()  )  ) 
	       u=1;  // slope=0     (horz)



	 if(  a.get_x() == a0.get_x()  &&  a.get_y() == a0.get_y() )
			u=1;                  //identical

	                         }


		
	//..................................................FIRST...........................................
	if(index_in_pa==0){
		point a1 =get_polygon_point(index_in_pa+1);
		point a0 =get_polygon_point(get_no_point()-1);

		if(a.get_x() != a0.get_x() && a.get_x() != a1.get_x() &&    a.get_y() != a0.get_y() && a.get_y() != a1.get_y()       ){
			if (slope(a,a0)==slope(a,a1))         u=1;	  //slope not 0 not oo   (inclined)
		}
     if(  ( a.get_x() == a0.get_x() && a.get_x() == a1.get_x() ) && ( a.get_y() != a0.get_y() && a.get_y() != a1.get_y()  )  ) 
	       u=1;   //slope=oo   (vertical)



		 if(  ( a.get_x() != a0.get_x() && a.get_x() != a1.get_x() ) && ( a.get_y() == a0.get_y() && a.get_y() == a1.get_y()  )  ) 
	       u=1;  // slope=0     (horz)



	 if(  a.get_x() == a0.get_x()  &&  a.get_y() == a0.get_y() )
			u=1;                  //identical

             }
	//....................................LAST............................................................
	if(index_in_pa ==   (get_no_point()-1)   ){
		point a1 = get_polygon_point(0);
		point a0 = get_polygon_point(get_no_point()-2);

		if(a.get_x() != a0.get_x() && a.get_x() != a1.get_x() &&    a.get_y() != a0.get_y() && a.get_y() != a1.get_y()       ){
			if (slope(a,a0)==slope(a,a1))         u=1;	  //slope not 0 not oo   (inclined)
		}
       if(  ( a.get_x() == a0.get_x() && a.get_x() == a1.get_x() ) && ( a.get_y() != a0.get_y() && a.get_y() != a1.get_y()  )  ) 
	       u=1;   //slope=oo   (vertical)



		 if(  ( a.get_x() != a0.get_x() && a.get_x() != a1.get_x() ) && ( a.get_y() == a0.get_y() && a.get_y() == a1.get_y()  )  ) 
	       u=1;  // slope=0     (horz)



	 if(  a.get_x() == a0.get_x()  &&  a.get_y() == a0.get_y() )

			u=1;                  //identical

	}


//                                        ........POINT AFTER IDENTICAL .......

	 if (  is_identical(index_in_pa+1) && is_identical(index_in_pa)==0      ){
		 if(index_in_pa == get_no_point()-2 ){
			 point a0=get_polygon_point(index_in_pa-1);
			 point a1=get_polygon_point(0);


			 if(a.get_x() != a0.get_x() && a.get_x() != a1.get_x() &&    a.get_y() != a0.get_y() && a.get_y() != a1.get_y()       ){
			if (slope(a,a0)==slope(a,a1))         u=1;	  //slope not 0 not oo   (inclined)
		}
       if(  ( a.get_x() == a0.get_x() && a.get_x() == a1.get_x() ) && ( a.get_y() != a0.get_y() && a.get_y() != a1.get_y()  )  ) 
	       u=1;   //slope=oo   (vertical)



		 if(  ( a.get_x() != a0.get_x() && a.get_x() != a1.get_x() ) && ( a.get_y() == a0.get_y() && a.get_y() == a1.get_y()  )  ) 
	       u=1;  // slope=0     (horz)


		 }
		 ////////////////////////////////////////////////////////////////////////////////////////////////
		 if( index_in_pa!=0  &&  index_in_pa!= get_no_point()-2){
                    point a0=get_polygon_point(index_in_pa-1);
					point a1=get_polygon_point(index_in_pa+2);


					if(a.get_x() != a0.get_x() && a.get_x() != a1.get_x() &&    a.get_y() != a0.get_y() && a.get_y() != a1.get_y()       ){
			if (slope(a,a0)==slope(a,a1))         u=1;	  //slope not 0 not oo   (inclined)
		}
       if(  ( a.get_x() == a0.get_x() && a.get_x() == a1.get_x() ) && ( a.get_y() != a0.get_y() && a.get_y() != a1.get_y()  )  ) 
	       u=1;   //slope=oo   (vertical)



		 if(  ( a.get_x() != a0.get_x() && a.get_x() != a1.get_x() ) && ( a.get_y() == a0.get_y() && a.get_y() == a1.get_y()  )  ) 
	       u=1;  // slope=0     (horz)

	
		
		 }
		
	 }
	 /////////////////////////////////////////////////////////////////////////////////////////////

	 if (    index_in_pa==0  && get_polygon_point(0).is_equal(  get_polygon_point(get_no_point()-1) )  ){
		 point a0 = get_polygon_point(get_no_point()-2);
		 point a1 =get_polygon_point(1);

		 if(a.get_x() != a0.get_x() && a.get_x() != a1.get_x() &&    a.get_y() != a0.get_y() && a.get_y() != a1.get_y()       ){
			if (slope(a,a0)==slope(a,a1))         u=1;	  //slope not 0 not oo   (inclined)
		}
       if(  ( a.get_x() == a0.get_x() && a.get_x() == a1.get_x() ) && ( a.get_y() != a0.get_y() && a.get_y() != a1.get_y()  )  ) 
	       u=1;   //slope=oo   (vertical)



		 if(  ( a.get_x() != a0.get_x() && a.get_x() != a1.get_x() ) && ( a.get_y() == a0.get_y() && a.get_y() == a1.get_y()  )  ) 
	       u=1;  // slope=0     (horz)

	 }
	 ///////////////////////////////////////////////////////////////////////////////////////////////////


	return u;

	}
	//...................................................................................................................................................................

 




	int count_point_without_red ( ){

		int red =0 ;

			for(int v=0 ; v<get_no_point() ; v++ ) {

			if(		is_red( v ) == 1  )  {   red++;       }

		}

			return (get_no_point()-red);


	}

//...................................................................................................................................
	
	float Polygon_Perimeter () {
		float perimeter =dis(get_polygon_point(0) ,    get_polygon_point (get_no_point()-1) );
		
		for(int i=0 ; i<get_no_point()-1 ; i++){
			
			perimeter=perimeter+dis( get_polygon_point(i) , get_polygon_point(i+1) );
		}
		return perimeter;

	}

	//.......................................................................................................................................................

	bool search_for_same_point (point r ){
		int u=0;

		for (int s=0 ; s< get_no_point() ; s++) {
	
			if(	r.is_equal(pa[s]) ) {   u=1; break; }
		}
		return u; 
	}
	//.................................................................................................................................................................

	float get_Area (){
		int v=0;
		float x_vertex [100];
		float y_vertex [100];
		float sum1=0;
		for(int i=0 ; i<get_no_point(); i++){

			if(is_red (i) == 0 ){
				x_vertex[v]=get_polygon_point_x(i);
				y_vertex[v]=get_polygon_point_y(i);
				v++;
			}
		}
		for(int j=0 ; j<v-1 ; j++) { sum1=sum1 +( (  x_vertex[j]* y_vertex[j+1] ) - ( y_vertex[j]* x_vertex[j+1] )  ); }
		   
		
		sum1=sum1 +( (  x_vertex[v-1]* y_vertex[0] ) - ( y_vertex[v-1]* x_vertex[0] )  );

			return fabs ( sum1/2   );
		
		}






	
	//..............................................................................................................................................................

	float max_mini(string max_mini  ){

		float max_x=get_polygon_point_x(0);
	float mini_x=get_polygon_point_x(0);
	float max_y=get_polygon_point_y(0);
	float mini_y=get_polygon_point_y(0);
	for(int i=1 ;i<get_no_point() ; i++){
		if (max_x < get_polygon_point_x(i)) max_x=get_polygon_point_x(i);

		if (max_y < get_polygon_point_y(i)) max_y=get_polygon_point_y(i);

		if(mini_x > get_polygon_point_x(i) ) mini_x =get_polygon_point_x(i);
			
		if(mini_y  >  get_polygon_point_y(i) ) mini_y =get_polygon_point_y(i);
	}
	if(max_mini=="max_x") return max_x;
	if(max_mini=="max_y") return max_y;
	if(max_mini=="mini_x") return mini_x;
	if(max_mini=="mini_y") return mini_y;
}










	//....................................................................................................................................................














};
//....................................................FUNCTIONS..........................................................................................



float dis(point p1 , point p2 ){
	return sqrt(pow( (p1.get_x() - p2.get_x() ), 2)  + pow (  (p1.get_y() - p2.get_y() )  ,2));
}

float slope ( point p1 , point p2){
	
	return (    (p2.get_y()-p1.get_y())/(p2.get_x()-p1.get_x())  );

}

float max_mini(string max_mini , point a[]  , int tot_no_of_point ){
	float max_x=a[0].get_x();
	float mini_x=a[0].get_x();
	float max_y=a[0].get_y();
	float mini_y=max_y;
	for(int i=1 ;i<tot_no_of_point ; i++){
		if (max_x < a[i].get_x()) max_x=a[i].get_x();

		if (max_y < a[i].get_y()) max_y=a[i].get_y();

		if(mini_x > a[i].get_x() ) mini_x =a[i].get_x();
			
		if(mini_y  > a[i].get_y() ) mini_y =a[i].get_y();
	}
	if(max_mini=="max_x") return max_x;
	if(max_mini=="max_y") return max_y;
	if(max_mini=="mini_x") return mini_x;
	if(max_mini=="mini_y") return mini_y;
}
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
float dis (float x , float x0 , float y0 , float y){
	return sqrt(pow( (x - x0 ), 2)  + pow (  (y - y0 )  ,2));
}
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,

int read_input_1 (string f ){
	int t= f.find (" ");
	int sd =f.length();
	string u =f.substr(t+1,sd-t);
	return atof(u.c_str());

}
	
	
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
 


int read_input_2 (string f ){
	int t=f.find(" ");
	int b=f.find(" ",t+1);
	int sd =f.length();
	string u =f.substr(b+1,sd-b);
	
	return atof(u.c_str());
}
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,

void read_rectangle( float x_rec [] , float y_rec [] ,string op ){
	int o=op.length();
	int d1=op.find("(") ;
		int d2=op.find("(",d1+1 ) ;
		int d3 = op.find("(" , d2+1) ;
		int d4= op.find("(" , d3+1) ;
		point g1,g2,g3,g4 ;
		g1.read_point(op.substr(d1,d2-d1-1));
		g3.read_point(op.substr(d3,d3-d2-1));
		g4.read_point (op.substr(d4,o-d4+1)) ;
		g2.read_point (op.substr(d2,d2-d1-1));

		x_rec[0]=g1.get_x();
		x_rec[1]=g2.get_x();
		x_rec[2]=g3.get_x();
		x_rec[3]=g4.get_x();
		y_rec[0]=g1.get_y();
		y_rec[1]=g2.get_y();
		y_rec[2]=g3.get_y();
		y_rec[3]=g4.get_y();
	

}



























int main () {



//.............................................................T2TEE3 w store polygon......................................................................
string   input;
string op;
polygon p[100];
point coord[10000];
int l=0,ll=0,c1=0,c2=0,u=0,k=0,ff=0,w=0,lr=0,bb=0,red_counter=0,TT=0,T=0;

getline(cin,input);
  
int n=input.length();

//..........................................................................................




for(int g=0 ; g<n ; g++){      

if(input.substr(g,1)=="(" ){

	
for (int i=1; input.substr(g+i,1)!="," ;i++){
	c2++;
}
    coord[l].set_x(atof(input.substr(g+1,c2).c_str()) );
	c2=0;
	l++;
	ff++;
	
		}

if(input.substr(g,1)==","){
			if (input.substr(g+1,1)!="("){ 
		
	
for (int j=1; input.substr(g+j,1)!=")" ;j++){
	
    c1 ++;
}
coord[ll].set_y (atof(input.substr(g+1,c1).c_str()) );
	         c1=0;
             ll++;


		}
	}
  
if(input.substr(g,1)==";" || input.substr(g,1)=="]"){

	for(int w=0 ; w<ff ; w++){
		lr=l;
		lr=lr-ff;
		p[k].set_polygon_point (coord[lr+w].get_x(),coord[lr+w].get_y(),w) ;
	
	}
	p[k].set_no_point(ff);
	k++;
	ff=0;
	lr=0;

}



	}

//...................................................................................................................................................
// l=total no of points ..........k = total no of polygons ............................
      
	
while(1){
	getline(cin,op);
	if (op =="Quit") return 0; 
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	if(op.substr(0,14) =="Polygon_Points" ){
	int bb=	read_input_1(op);

 for(int t=0 ; t<p[bb-1].get_no_point() ;t++){    p[bb-1].print_one_point_of_polygon(t);   }

	}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<


	if(op.substr(0,14)=="Point_Polygons"){
		string poi;
		poi=op.substr(op.find(" ")+1 , op.length()-op.find(" ") );
		point z ;
		T=0;
		z.read_point(poi);
		for(int q=0 ; q<k ;q++ ) {

			for (int t=0 ;t<p[q].get_no_point() ; t++){
				 
					if(z.get_x() ==p[q].get_polygon_point_x(t) && z.get_y() ==p[q].get_polygon_point_y(t) ){
					T++;
					if(T>1) cout<<",";
					cout<<q+1;
					break;
					}
			
				}

			}
		if(T==0) cout<<"none";
		}

	

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	if(op=="Total_Redundant_Points"){
		 for(int m=0 ; m<k; m++ ){

	for(int v=0 ; v<p[m].get_no_point() ; v++ ) {

			if(		p[m].is_red(v) ) {   red_counter++;       }

		}
	 }

		 if(red_counter>0) cout<<red_counter;
		 else cout<<"none";
		 red_counter=0;

	}
	//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	if(op=="Number_Polygons") {cout<<k;}

	//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	if(op=="Total_Number_Points") {  cout<<l;     }


	//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


	if(op.substr(0,25)=="List_Polygons_Points More"){
		int more =read_input_2(op);
	     int R=0,cou=0;
		 
		 
		 while(cou<k){
	
			 if	( p[cou].count_point_without_red() > more ) {
			R++;
			if (R>1) cout<<",";
			cout<<cou+1;
		}
			 cou++;
		}
		
	if(R==0) cout<<"none";
		
	}	
	 //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


	if(op.substr(0,25)=="List_Polygons_Points Less"){
		int less=read_input_2(op);
	  
	     int R1=0,count1=0;
		 
		 
		 while(count1<k){
	
			 if	( p[count1].count_point_without_red() < less) {
			R1++;
			if (R1>1) cout<<",";
			cout<<count1 +1;
		}
			 count1++;
		}
		
	if(R1==0) cout<<"none";
		
	}	
	  //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	if(op.substr(0,26)=="List_Polygons_Points Equal"){
		int equal=read_input_2(op);
	     int R2=0,count2=0;
		 
		 
		 while(count2<k){
	
			 if	( p[count2].count_point_without_red() == equal) {
			R2++;
			if (R2>1) cout<<",";
			cout<<count2 +1;
		}
			 count2++;
		}
		
	if(R2==0) cout<<"none";
		
	}	


	
	//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


	if(op.substr(0,17)=="Polygon_Perimeter")  {
		int dd=read_input_1(op);
		cout<<p[dd-1].Polygon_Perimeter();
	}

	//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	if(op=="Minimum_X")    cout<<max_mini("mini_x", coord , l);
	
	if(op=="Minimum_Y")    cout<<max_mini("mini_y", coord , l);

	if(op=="Maximum_Y")    cout<<max_mini("max_y", coord , l);

	if(op=="Maximum_X")    cout<<max_mini("max_x", coord , l);

	//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	if(op =="Enclosing_Rectangle")
		cout<<"("<< max_mini("mini_x", coord , l)<<","<< max_mini("max_y", coord , l)<<")" <<","
		<<"("<<max_mini("max_x", coord , l)<<","<< max_mini("max_y", coord , l)<<")"<<","
		<<"("<<max_mini("max_x", coord , l)<< "," <<max_mini("mini_y", coord , l)<< ")"<<","
     	<< "(" <<max_mini("mini_x", coord , l)<< ","<< max_mini("mini_y", coord , l)<<")";
		
	//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	if(op=="List_Triangles"){
		int Oo=0;
	for(int YY=0; YY<k ; YY++){
		  
			if(p[YY].count_point_without_red() == 3)  {
				Oo++;
				if(Oo>1)  cout<<",";  
				cout<<YY+1;
			}}
	if(Oo==0) cout<<"none";
	}
                                                    	
	
	
	//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	if(op=="List_Rectangles") {
		int M=0,off=0;
		int H=0,N=0;
		float x1,x2,x3,x4,y1,y2,y3,y4;
		point t1,t2,t3,t4;
		for(int mm=0 ; mm<k ; mm++){
			if (p[mm].count_point_without_red() == 4 ){
				for(int nn=0 ; nn<p[mm].get_no_point() ; nn++) {
					if ( p[mm].is_red( nn) ==0 ){
						M++;
						if(M==1)	{  x1=p[mm].get_polygon_point_x(nn);    y1=p[mm].get_polygon_point_y(nn);   }
						if(M==2)	{  x2=p[mm].get_polygon_point_x(nn);    y2=p[mm].get_polygon_point_y(nn);   }
						if(M==3)	{  x3=p[mm].get_polygon_point_x(nn);    y3=p[mm].get_polygon_point_y(nn);   }
						if(M==4)	{  x4=p[mm].get_polygon_point_x(nn);    y4=p[mm].get_polygon_point_y(nn);   M=0; }
						N=1;
						
					
					}}}

			if ( dis(x1,x3,y1,y3) ==  dis(x2,x4,y2,y4) && N==1){
			
				H++;
				if(H>1) {   cout<<",";  }
				cout<<mm+1;
				N=0;
				off=1;
		}
		if( mm == k-1 && off==0) cout<<"none";	
		}
			
	}

			
	
	//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	if(op=="List_Trapezoid"){
		int NB=0,H=0;
		int UV=0,off=0;
		float x1,x2,x3,x4,y1,y2,y3,y4;

		for(int q=0 ; q<k ; q++){
			if (p[q].count_point_without_red() == 4 ){
				for(int nn=0 ; nn<p[q].get_no_point() ; nn++) {
					if ( p[q].is_red( nn ) ==0 ){
						NB++;
						if(NB==1)	{  x1=p[q].get_polygon_point_x(nn);    y1=p[q].get_polygon_point_y(nn);   }
						if(NB==2)	{  x2=p[q].get_polygon_point_x(nn);    y2=p[q].get_polygon_point_y(nn);   }
						if(NB==3)	{  x3=p[q].get_polygon_point_x(nn);    y3=p[q].get_polygon_point_y(nn);   }
						if(NB==4)	{  x4=p[q].get_polygon_point_x(nn);    y4=p[q].get_polygon_point_y(nn);   NB=0; }
						UV=1;
						}}}
		//	if(x2==x1 && x4==x3  ||  x2==x3 && x4==x1)
			if(  (x4==x1 && x2==x3 && x1 != x2 && UV==1) && (  (x1==x2 && x3!=x4) || (x1!=x2 && x3==x4)  )     ) { 
				H++;
				if(H>1) {   cout<<",";  }
				cout<<q+1;
				UV=0;
				off=1;
			}         
			//.........................................................ver bases trapzoid..........................





			else if(  ( (y2-y1)/(x2-x1) ) == ( (y4-y3)/(x4-x3) )  && ( (y4-y1)/(x4-x1) ) != ( (y3-y2)/(x3-x2) )  
				||  ( (y2-y1)/(x2-x1) ) != ( (y4-y3)/(x4-x3) )  && ( (y4-y1)/(x4-x1) ) == ( (y3-y2)/(x3-x2) ) ) {
				if(dis(x1,x3,y1,y3) != dis(x2,x4,y2,y4)){
					if(UV ==1 ){
				H++;
				if(H>1) {   cout<<",";  }
				cout<<q+1;
				UV=0;
				off=1;
					}
			}
			}
			
      if (q== k-1 && off== 0) cout<<"none"; 
		}
	}
	//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	if(op.substr(0,25)=="List_Points_Polygons More"){
		int G=0,more1=read_input_2(op);
		int Counter=0,ref=0,lk=0;
		
	
		
			for(int q=0 ; G<=k-1  ; q++){

				if(p[G].is_identical(q) == 0 ){

				for(int s=0 ; s<k ;s++){	if( p[s].search_for_same_point( p[G].get_polygon_point(q) )  )  Counter++;    }
						
			if ( Counter > more1) { 
				ref++; 

				if (G==0)	{if(ref > 1)cout<<",";     cout<<"("<< p[G].get_polygon_point_x(q)<<","<< p[G].get_polygon_point_y(q)<<")"; }

				if (G>0){

					
					for(int io=0 ; io<G ;io++){	if( p[io].search_for_same_point( p[G].get_polygon_point(q) )  )   lk=1; }


          if (lk==0){ if(ref > 1)cout<<",";	       cout<<"("<< p[G].get_polygon_point_x(q)<<","<< p[G].get_polygon_point_y(q)<<")"; }
		  
				}
			} 
			}		
				
				
				
				if(q  == (p[G].get_no_point()-1) ) {  G++; q=0; lk=0; }  
				Counter=0;
			
		}
			if(ref==0) cout<<"none";
	}
	
	//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	if(op.substr(0,25)=="List_Points_Polygons Less"){
		int G1=0,less1=read_input_2(op),lk=0;
		int Counter1=0,ref1=0;
		
	
		
			for(int q=0 ; q<p[G1].get_no_point() ; q++){

				if(p[G1].is_identical(q) == 0 ){

				for(int s=0 ; s<k ;s++){	if( p[s].search_for_same_point( p[G1].get_polygon_point(q) )  )  Counter1++;    }
						
			if ( Counter1 < less1) { 
				ref1++; 

				if (G1==0)	{if(ref1 > 1)cout<<",";     cout<<"("<< p[G1].get_polygon_point_x(q)<<","<< p[G1].get_polygon_point_y(q)<<")"; }

				if (G1>0){

					
					for(int io=0 ; io<G1 ;io++){	if( p[io].search_for_same_point( p[G1].get_polygon_point(q) )  )   lk=1; }


          if (lk==0){ if(ref1 > 1)cout<<",";	cout<<"("<< p[G1].get_polygon_point_x(q)<<","<< p[G1].get_polygon_point_y(q)<<")"; }
		  
				}
			} 
			}		
				
				
				if(G1 == k-1) break;
				if(q  == (p[G1].get_no_point()-1) ) {  G1++; q=0; lk=0; }  
				Counter1=0;
			
		}
			if(ref1==0) cout<<"none";
	}

	//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	if(op.substr(0,26)=="List_Points_Polygons Equal"){
		int G2=0,Equal,lk=0;
		int Counter2=0,ref2=0;
		Equal=read_input_2(op);
	
		
			for(int q=0 ; q<p[G2].get_no_point() ; q++){

				if(p[G2].is_identical(q) == 0 ){

				for(int s=0 ; s<k ;s++){	if( p[s].search_for_same_point( p[G2].get_polygon_point(q) )  )  Counter2++;    }
						
			if ( Counter2 == Equal) { 
				ref2++; 

			if (G2==0)	cout<<"("<< p[G2].get_polygon_point_x(q)<<","<< p[G2].get_polygon_point_y(q)<<")";

				if (G2>0){

					
					for(int io=0 ; io<G2 ;io++){	if( p[io].search_for_same_point( p[G2].get_polygon_point(q) )  )   lk=1; }


          if (lk==0){

				if(ref2 > 1)cout<<",";

				cout<<"("<< p[G2].get_polygon_point_x(q)<<","<< p[G2].get_polygon_point_y(q)<<")";
				}
		  
				}
			} 
			}		
				
				
				if(G2 == k-1) break;
				if(q  == (p[G2].get_no_point()-1) ) {  G2++; q=0; lk=0; }  
				Counter2=0;
			
		}
			if(ref2==0) cout<<"none";
	}

	
	//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	if (op.substr(0,12) == "Polygon_Area" ){
	int zx= read_input_1 (op);
	if (zx > k) cout<<"none" ;
	else cout<<p[zx-1].get_Area();
	}
	//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	if(op.substr(0,19)=="Polygons_Area_Range" ) {
		int U , A ,B ,C ,o=0;
		float mini_area,max_area;
		U=op.find (" ");
		A=op.find(",");
		B=op.length();
		mini_area=  atof(op.substr (U+1,A-1-U).c_str());
		max_area= atof(op.substr (A+1,B-A).c_str());
		for (C=0 ; C<k ; C++){
		if(	p[C].get_Area() >= mini_area && p[C].get_Area() <=max_area ){ o++;
		if(o>1) cout<<",";
		if(o) cout<<C+1;
		}
		}
	
		if(o==0) cout<<"none";

	}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>	 

	if(op.substr(0,16) == "Inside_Rectangle" ){
		int o=op.length();
		int zz=0;
		float x_rec[4] , y_rec[4];
		

		read_rectangle(x_rec,y_rec,op);
		float max_x_rec = x_rec[0];
		float mini_x_rec = x_rec[0];
		float max_y_rec = y_rec[0];
		float mini_y_rec = y_rec[0];

		for(int z=0 ;z<4 ; z++) { 
		if (x_rec[z] > max_x_rec) max_x_rec=x_rec[z] ;

		if (y_rec[z] > max_y_rec) max_y_rec=y_rec[z] ;

		if (x_rec[z] < mini_x_rec) mini_x_rec=x_rec[z] ;

	    if (y_rec[z] < mini_y_rec) mini_y_rec=y_rec[z] ;
			
		}

		

		for(int f=0 ; f<k ; f++) { 
		if ( p[f].max_mini("max_x")<= max_x_rec   

		&& p[f].max_mini("mini_x")>=  mini_x_rec 

	   &&  p[f].max_mini("max_y") <= max_y_rec      
	   
		&& p[f].max_mini("mini_y") >= mini_y_rec ){			
					zz++;
					if (zz>1) cout<<","; 
					cout<<f+1;
	
				
		}
		}

	
		
		if(zz==0) cout<<"none";
				
		}
	//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	if(op.substr(0,13)=="Inside_Circle"){
		int u=op.find(" ");
		int o=op.find(")");
		int i=op.find("," , op.find(",")+1 );
		int b=op.length();
		int qq=0,nbn=0;
		point c ;
		c.read_point( op.substr(u,o-u+1) );
		float raduis = atof(op.substr (i+1,b-i).c_str());
		
		for(int s=0 ; s<k ; s++ ){
			for(int t=0; t<p[s].get_no_point(); t++){

				if( dis(c,p[s].get_polygon_point(t) ) <= raduis ) qq=1;
				else { qq=0;  break;}
		}
			if(qq==1){
				nbn++;
				if(nbn>1) cout<<",";
				cout<<s+1;
				qq=0;
			}
		}

		if(nbn==0) cout<<"none";
	}

}
		
return 0 ;
}
