#include <bits/stdc++.h>
#include "quickhull3d.h"
using namespace std;

int main()
{
    vector<double> c;
    double x,y,z;
    int i=0,n=0;
    fstream inp("B:\\Summer Training '15\\depthHand.txt",ios_base::in);//input file containing 3d points as input
    while(inp>>x && inp>>y && inp>>z)
    {
        c.push_back(x);
        c.push_back(y);
        c.push_back(z);
        n++;//counting the number of points
        i++;
    }
    /****just for test run***
    //printf("Enter the number of input points : ");
    //scanf("%d",&n);
    //printf("Enter the points as x y z ...\n");
    //for(i=0;i<n;i++)
    //    scanf("%lf %lf %lf",&c[i*3],&c[i*3+1],&c[i*3+2]);
    //for(i=0;i<n;i++)
      //  printf("%lf %lf %lf\n",c[i*3],c[i*3+1],c[i*3+2]);***/
    QuickHull3D *hull = new QuickHull3D(c,n*3);
    /***the following commented part of code can give an output file of just the required convex hull points ***/
    //vector<Point3D *> vertices = hull->getVertices();
    //printf("The output convex hull points are:\n");
    /*
    if(op.is_open())
    {
        for(i=0;i<vertices.size();i++)
            op<<vertices[i]->x<<" "<<vertices[i]->y<<" "<<vertices[i]->z<<endl;
        op.close();
    }*/
    //QuickHull3D *hull = new QuickHull3D(getpoints(), getnumberofpoints());
    vector<Point3D *> vertices = hull->getVertices();
    vector<vector<int> > faceIndices = hull->getFaces();
    ofstream op("facewise.txt");/**will store output convex hull points face-wise, each face separated by a line break***/
    //vector<Face> vf;
    if(op.is_open())
    {
        for (int i = 0; i < faceIndices.size(); i++){
        //cout<<faceIndices[i].size()<<endl;
        //Face f = Face();
        for (int j = 0; j < faceIndices[i].size(); j++){
            Point3D *temp = vertices[faceIndices[i][j]];
            //f.addpoint(Point(temp->x, temp->y, temp->z));
            op<<temp->x<<" "<<temp->y<<" "<<temp->z<<endl;
        }
        op<<endl;
    }
    op.close();
    }
        //vf.push_back(f);
    printf("Done");
    return 0;
}
