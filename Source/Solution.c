double tinh(int hp1, int hp2, int d)
{
    double pr, p1,p2;
    int h1,h2;
    p1=(double)hp1*(1000-d)/1000;
    p2=(double)hp2*d/1000;
    h1=(hp1+hp2)%100;
    h2=(h1*hp2)%100;
    if(h1*p1+h2*p2==0)
    {
        if(h1==h2 && h2==0)pr=0;
        else if(h1==0 || h2==0)
        {
            if(p1<p2) pr=0;
            else pr=1;
        }
    }
    else
    {
        pr=(h1*p1-h2*p2)/(h1*p1+h2*p2);
        if(pr<0)pr=0;
        else if(pr>1) pr=1;
    }
    return pr;
}
double giaotranh_binhthuong(int hp1, int hp2, int d)
{
    double pr;
    if(hp2==888)
    {
        if(hp1==777 || hp1==888 || hp1==900)
        {
            pr=tinh(hp1,hp2,d);
        }
        else if(hp1==999)
        {
            pr=1;
        }
        else
        {
            pr=0.01;
        }
    }
    else if(hp1==777)
    {
        double p1,p2;
        int h1,h2;
        p1=(double)hp1*(1000-d)/1000;
        p2=(double)hp2*d/1000;
        h1=(hp1+hp2)%100;
        h2=(h1*hp2)%100;
        if(p1<p2 || h1<h2)
        {
            d=1;
            pr=tinh(hp1,hp2,d);
        }
        else pr=tinh(hp1,hp2,d);
    }
    else if(hp1==888)
    {
        int h1,h2;
        double p1,p2;
        h1=(hp1+hp2)%100;
        h2=(h1*hp2)%100;
        h1=h1*10;
        p1=(double)hp1*(1000-d)/1000;
        p2=(double)hp2*d/1000;
        if(h1*p1+h2*p2==0)
        {
            if(h1==h2 && h2==0) pr=0;
            else if(h1==0 || h2 ==0)
            {
                if(p1<p2)pr=0;
                else pr=1;
            }
        }
        else
        {
            pr=(h1*p1-h2*p2)/(h1*p1+h2*p2);
            if(pr<0)pr=0;
            else if(pr>1)pr=1;
        }
    }
    else if(hp1==900)
    {
        pr=tinh(hp1,hp2,d);
        if(pr<0.5)pr=0.5;
    }
    else if((hp1==284 && hp2==220)||(hp1==220 && hp2==284))
    {
        pr=0.5;
    }
    else
    {
        pr=tinh(hp1,hp2,d);
    }
    return pr;
}
double giaotranh(int hp1,int hp2, int d)
{
    double pr;
    int h1,h2;
    h1=(hp1+hp2)%100;
    h2=(h1*hp2)%100;
    if(d==987)
    {
        if(hp1==999 || (h1+h2==99))
        {
            pr=giaotranh_binhthuong(hp1,hp2,d);
        }
        else pr=0;
    }
    else pr=giaotranh_binhthuong(hp1,hp2,d);
    return pr;
}

void combat(int hp1, int hp2, int d)
{
    printf("%0.2f",giaotranh(hp1,hp2,d));
}