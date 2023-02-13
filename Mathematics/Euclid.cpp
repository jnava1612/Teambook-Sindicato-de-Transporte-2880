
ll gcd(ll a, ll b){return b==0? a:gcd(b,a%b);}

int x, y, d;
void extendedEuclid(int a, int b)//ecuacion diofantica ax + by = d
{
	if(b==0) {x=1; y=0; d=a; return;}
	extendedEuclid(b,a%b);
	int x1=y;
	y = x-(a/b)*y;
	x=x1;
}


Encuentra x, y en la ecuación de la forma ax + by = c             
Agregar Extended Euclides.

ll g;
bool diophantine(ll a, ll b, ll c) {
	x = y = 0;
	if(!a && !b) return (!c); // sólo hay solución con c = 0
	g = euclid(abs(a), abs(b));
	if(c % g) return false;
	a /= g; b /= g; c /= g;
	if(a < 0) x *= -1;
	x = (x % b) * (c % b) % b;
	if(x < 0) x += b;
	y = (c - a*x) / b;
	return true;
}