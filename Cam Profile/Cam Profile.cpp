#include<iostream>
#include<vector>
#define PI 3.14
using namespace std;

double Convert(double radian)
{
	return(radian * (180 / PI));
}
int main()
{
	double H_R;
	double H_F;
	double T;
	double Rb;
	int n;
	int Int;
	double Sum = 2.5;
	double ti = 0;
	double m;

	cout << "Enter Harmonic Rise: ";
	cin >> H_R;
	cout << "Enter Harmonic Fall: ";
	cin >> H_F;
	cout << "Enter time consumed during a single interval:" << endl;
	cin >> T;
	cout << "Enter Base Circle Radius:" << endl;
	cin >> Rb;
	/*cout << "Enter the number of the intervals:" << endl;
	cin >> n;
	cout << "Enter the spesifc interval that you have in seconds:" << endl;
	for (int i = 0; i <= n; i++)
	{
		cin >> Int;
		Sum += Int;
	}*/
	double Wcam = 1.0 / Sum;
	cout << "Enter the number of the intervals:" << endl;//2.5
	cin >> m;
	double W1;
	double W2;
	double Cam_Ang_Rad;
	double Cam_Ang_degrees;
	long double F_D;
	double F_V;
	double F_A;
	double R_X;
	double R_Y;

	//cout << " Wcam =" << Wcam << endl;

	for (double t = 0.000; t <= m; t++)
	{ 
		
		cout << t << endl;
		
		W1 = Wcam * 60;
		W2 = Wcam * PI * 2;
		Cam_Ang_Rad = W2 * t;
		
		
		
		
		if (t >= 1.255 && t <= 2)
		{
			//=(1/2)*(1+COS(先()*(A276-1,25)/0,75))
			F_D = ((1.0000000000 / 2.000000000) * (1.000000000 + cos((PI)*(t-1.25))) / T);
			cout << "Follower Displacement= " << F_D << endl;
			//=((-先()*1)/(2*0,75))*(SIN(先()*(A276-1,25)/(0,75)))
			F_V = (((-PI * 1.0000000000) / (2.000000000 * 0.75) * (sin(PI * (t-1.25))) / 0.75));
			cout << "Follower Velocity= " << F_V << endl;
			//=(-(先()^2*1)/(2*0,75^2))*(COS(先()*(A276-1,25)/(0,75)))
			F_A = ((-pow(PI, 2) * 1) / (2 * pow(0.75, 2)) * (cos(PI * (t-1.25))) / 0.75);
			cout << "Follower Accel= " << F_A << endl;

		}
		if (t <= 0.75 || t == 0.75)
		{
			F_D = (1.0000000000 / 2.000000000) * (1.000000000 - cos((PI)*t / T));
			cout << "Follower Displacement= " << F_D << endl;
			F_V = ((PI * 1.0000000000) / 2.000000000 * 0.75) * (sin(PI * t) / 0.75);
			cout << "Follower Velocity= " << F_V << endl;
			F_A = (pow(PI, 2) * 1) / (2 * pow(0.75, 2)) * (cos(PI * t / 0.75));
			cout << "Follower Accel= " << F_A << endl;
			
		}
		if (t >= 0.755 && t<=1.25)
		{
			F_D = 1;
			cout << "Follower Displacement= " << F_D << endl;
			F_V = 0;
			cout << "Follower Velocity= " << F_V << endl;
			F_A = 0;
			cout << "Follower Accel= " << F_A << endl;
		}
		if (t >= 2.005 && t <= 2.5)
		{
			F_D = 0;
			cout << "Follower Displacement= " << F_D << endl;
			F_V = 0;
			cout << "Follower Velocity= " << F_V << endl;
			F_A = 0;
			cout << "Follower Accel= " << F_A << endl;
		}
		t = t - 1;
		t += 0.005;
		
		

		R_X = (Rb + F_D) * sin(Cam_Ang_Rad);
		R_Y = (Rb + F_D) * cos(Cam_Ang_Rad);
		//cout << "Wcam = " << Wcam << endl;
		// Sum += t;
		// W1 = Wcam * 60;
		 cout << "W1 =" << W1 << endl;
		// W2 = Wcam * PI * 2;
		 cout << "W2 =" << W2 << endl;
		// Cam_Ang_Rad = W2 * t;
		 cout << "Cam_Ang_Rad=" << Cam_Ang_Rad << endl;
		// cout << double(Cam_Ang_Rad) << endl;
		 Cam_Ang_degrees = Convert(Cam_Ang_Rad);
		
		
		 cout << "Cam_Ang_degrees=" << Cam_Ang_degrees << endl;
		
		

		 cout << "R_X=" << R_X << endl;
		 cout << "R_Y=" << R_Y << endl;
		// cout << " Wcam =" << Wcam << endl;
		// cout << " W1 = " << W1 << endl;
		// cout << " W2 = " << W2 << endl;
		// cout << "Cam_Ang_Rad:" << endl;
		 

	}

	
}