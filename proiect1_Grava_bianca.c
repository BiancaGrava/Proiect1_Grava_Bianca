#include <stdio.h>   // Pentru citiri si afisari
#include <time.h>    // Pentru manipularea datelor calendaristice
#include <string.h>  //Pentru lucrul cu siruri de caractere
#include <stdlib.h>

struct tranz
{
    char tip[20];
    char descriere[20];
    double suma;
    char Data[20];
} v[251];
int nt;

/*int read_int()
{
    int num=0;
    char nr[10];
    while (num==0)//se asigura ca va fi citit un numar, iar din moment ce in problema noastra introducerea
//valorii 0 ar fi ilogica pentru valoarea unei zile, luni sau a unui an(singurele entitati float ale programului),
//putem folosi valoarea 0 drept valoare de control a citirii
    {
        printf("se asteapta un intreg\n");
        if (fgets(nr, sizeof(nr), stdin) != NULL)//verifica daca un sir de caractere de marimea corecta a fost citit cu succes
        {
            if (sscanf(nr, "%d", &num) == 1) //verifica daca sirul de caractere din nr poate fi transformat in int,
//iar daca da, num retine valoare respectiva ca intreg
            {
                // intreg stocat cu succes
            }
            else
            {
                printf("Va rugam introduceti un numar intreg.\n");
                num = 0;
            }
        }
        else
        {
            printf("Error reading input.\n");
            num=0;
        }
    }
    return num;
}


int read_float()
{
    double num=0;
    char nr[200];
    while (num==0)//se asigura ca va fi citit un numar, iar din moment ce in problema noastra introducerea
//valorii 0 ar fi ilogica pentru valoarea unei sume(singura entitate float a programului), putem folosi valoarea 0
//drept valoare de control a citirii
    {
        printf("se asteapta un nr rational: ");
        if (fgets(nr, sizeof(nr), stdin) != NULL)//verifica daca un sir de caractere de marimea corecta a fost citit cu succes
        {
            if (sscanf(nr, "%lf", &num) == 1) //verifica daca sirul de caractere din nr poate fi transformat in float,
//iar daca da, num retine valoare respectiva ca float
            {
                // float stocat cu succes
            }
            else
            {
                printf("Va rugam introduceti un numar rational.\n");
                num = 0;
            }
        }
        else
        {
            printf("Error reading input.\n");
            num=0;
        }
    }
    return num;
}*/

char* read_tip()
{
    static char tip[20];
    tip[0]='\0';
    while(tip[0]=='\0')
    {
        printf("Tip: venit sau tranzactie- ");
        scanf("%s",tip);
        if(strcmp(tip,"venit")!=0&&strcmp(tip,"tranzactie")!=0)
        {
            printf("tipul nu este cunoscut, va rugam incercati din nou");
            tip[0]='\0';
        }
    }
    return tip;
}

char* dateToString(int zi, int luna, int an)
{
    static char dateString[20];
    sprintf(dateString, "%02d-%02d-%04d", zi, luna, an);
    return dateString;
}

char* citire_data_valida()
{
    static char dataa[20];
    int zi=0,luna=0,an=0;
    while(zi==0)
    {
    	printf("\nIntroduceti ziua: ");
        scanf("%d",&zi);
        if(zi<1||zi>31)
        {
            zi=0;
            printf("zi incorecta. introduceti din nou!\n");
        }
    }
    while(luna==0)
    {
    printf("Introduceti luna: ");
        scanf("%d",&luna);
        if(luna<1||luna>12)
        {
            luna=0;
            printf("luna incorecta. introduceti din nou!\n");
        }
    }
    while(an==0)
    {
    printf("Introduceti anul: ");
        scanf("%d",&an);
        if(an<2000||an>2023)
        {
            an=0;
            printf("an indisponibil. introduceti din nou!\n");
        }
    }
    strcpy(dataa,dateToString(zi,luna,an));
    return dataa;
}

void introd_tranz()
{
    nt++;
    char s[20],desc[20],data[20];
    printf("Introduceti tipul tranzactiei: ");
    strcpy(s,read_tip());//scanf("%s",s);
    strcpy(v[nt].tip,s);
    printf("\nIntroduceti o descriere: ");
    scanf("%s",desc);
    strcpy(v[nt].descriere,desc);
    double sum=0;
    while(sum==0)
    {
        printf("\nIntroduceti suma: ");
        scanf("%lf",&sum);
        if(sum>0)
           v[nt].suma=sum;
        else
        {
           sum=0;
            printf("Suma invalida\n");
        }
    }
    strcpy(data,citire_data_valida());
    strcpy(v[nt].Data,data);
}

double calc_bal()
{
    int i;
    double s=0;
    for(i=1; i<=nt; i++)
        if(strcmp(v[i].tip,"venit")==0)
            s+=v[i].suma;
        else
            s-=v[i].suma;
    return s;
}

void afis_tranzactii()
{
    int i;
    int ok=0;
    for(i=1; i<=nt; i++)
    {
        printf("%s",v[i].tip);
        printf(" ");
        printf("%s",v[i].descriere);

        printf(" ");
        printf("%f",v[i].suma);
        printf(" ");
        printf("%s",v[i].Data);
printf("\n"); 
    ok=1;   }
    if(ok==0)
    printf("Nu exista tranzactii de afisat\n");
    printf("\n");
}

void afis_e_timp()
{
    int i;
    char datai[20],dataf[20];
    printf("\nIntroduceti data de inceput: ");
    strcpy(datai,citire_data_valida());
    printf("\nIntroduceti data de final: ");
    strcpy(dataf,citire_data_valida());
    int zi,li,ai,zf,lf,af;
    if (sscanf(datai, "%d-%d-%d", &zi, &li, &ai) == 3)
    {
        zi=zi;
        li=li;
        ai=ai;
    }
    if (sscanf(dataf, "%d-%d-%d", &zf, &lf, &af) == 3)
    {
        zf=zf;
        lf=lf;
        af=af;
    }
    int t=0;
    int oka=0,okl=0,okz=0;
    if(ai==af)
        oka=1;
    if(li==lf)
        okl=1;
    if(zi==zf)
        okz=1;
    if(okz==1)
        for(i=1; i<=nt; i++)
        {
            int zv,lv,av;
            if (sscanf(v[i].Data, "%d-%d-%d", &zv, &lv, &av) == 3)
            {
                zv=zv;
                lv=lv;
                av=av;
            }
            if(zv==zi)
            {
                printf("%s",v[i].tip);
                printf(" ");
                printf("%s",v[i].descriere);

                printf(" ");
                printf("%f",v[i].suma);
                printf(" ");
                printf("%s",v[i].Data);
                printf("\n");
                t=1;
            }
        }
    else
    {
        if(okl==1)
            for(i=1; i<=nt; i++)
            {
                int zv,lv,av;
                if (sscanf(v[i].Data, "%d-%d-%d", &zv, &lv, &av) == 3)
                {
                    zv=zv;
                    lv=lv;
                    av=av;
                }
                if((zv>=zi&&zv<=zf)&&(lv==li))
                {
                    printf("%s",v[i].tip);
                    printf(" ");
                    printf("%s",v[i].descriere);

                    printf(" ");
                    printf("%f",v[i].suma);
                    printf(" ");
                    printf("%s",v[i].Data);
                    printf("\n");
                    t=1;
                }
            }
        else 
        {
        	if(oka==1)
			for(i=1; i<=nt; i++)
		    	{
				int zv,lv,av;
				if (sscanf(v[i].Data, "%d-%d-%d", &zv, &lv, &av) == 3)
				{
				    zv=zv;
				    lv=lv;
				    av=av;
				}
				if(((lv>li&&lv<lf)&&(lv==li))||(lv==li&&zv>=zi&&av>=ai)||(lv==lf&&zv<=zf&&av<=af))
				{
				    printf("%s",v[i].tip);
				    printf(" ");
				    printf("%s",v[i].descriere);

				    printf(" ");
				    printf("%f",v[i].suma);
				    printf(" ");
				    printf("%s",v[i].Data);
				    printf("\n");
				    t=1;
				}
		    	}
		else
		{
			for(i=1; i<=nt; i++)
		    	{
				int zv,lv,av;
				if (sscanf(v[i].Data, "%d-%d-%d", &zv, &lv, &av) == 3)
				{
				    zv=zv;
				    lv=lv;
				    av=av;
				}
				if(av>ai&&av<af)
				{
				    printf("%s",v[i].tip);
				    printf(" ");
				    printf("%s",v[i].descriere);

				    printf(" ");
				    printf("%f",v[i].suma);
				    printf(" ");
				    printf("%s",v[i].Data);
				    printf("\n");
				    t=1;
				}
				else
				{
				if((av==ai&&lv>li)||(av==af&&lv<lf))
				{
				    printf("%s",v[i].tip);
				    printf(" ");
				    printf("%s",v[i].descriere);

				    printf(" ");
				    printf("%f",v[i].suma);
				    printf(" ");
				    printf("%s",v[i].Data);
				    printf("\n");
				    t=1;
				}
				else
				if((av==ai&&lv==li&&zv>=zi)||(av==af&&lv==lf&&zv<=zf))
				{
				    printf("%s",v[i].tip);
				    printf(" ");
				    printf("%s",v[i].descriere);

				    printf(" ");
				    printf("%f",v[i].suma);
				    printf(" ");
				    printf("%s",v[i].Data);
				    printf("\n");
				    t=1;
				}
				}
		    	}
		}
        }
    }
    if(t==0)
    	printf("nu s-au efectuat tranzactii intre data de inceput si cea de final.\n");
}

void salveaza()
{
	char const *nume="Tranzactii.txt";
	FILE*file=fopen(nume,"w");
	if(file==NULL)
	{
		printf("Fila nu se poate deschide %s\n",nume);
		return;
	}
	for(int i=1;i<=nt;i++)
		fprintf(file,"%s\t%s\t%f\t%s\n",v[i].tip,v[i].descriere,
		v[i].suma,v[i].Data);
	fclose(file);
	printf("Date salvate cu succes!\n");
}


void importa()
{
	char const *nume="Tranzactii.txt";
	FILE*file=fopen(nume,"r");
	if(file==NULL)
	{
		printf("Fisierul e gol %s\n",nume);
		return;
	}
		 while(fscanf(file,"%s\t%s\t%lf\t%s\n",
		 v[nt].tip,v[nt].descriere,&v[nt].suma,v[nt].Data)!=EOF)
		nt++;
		
	fclose(file);
	printf("Date importate cu succes!\n");
}

//pana la functia main, restul functiilor sunt teste ale functiilor de mai sus

int test_read_tip() {
    // read_tip returneaza doar "venit" sau "tranzactie", deci:
    char* tip = read_tip();
    if(strcmp(tip, "venit") == 0 || strcmp(tip, "tranzactie") == 0)
    return 1;
    else
    return 0;
}

int test_dateToString() {
//verifica daca data este formatata corect in functie in baza unor nmere intregi, parametrii ai functiei
    char* dateString = dateToString(1, 11, 2023);
    if (strcmp("01-11-2023", dateString)==0)
    	return 1;
    else
    	return 0;
}
/*void set_fake_input(const char* input) {
    freopen("fake_input.txt", "w", stdin);
    printf("%s", input);
    fclose(stdin);
}
int test_citire_data_valida() {
//setam un input fals pe care sa-l putem folosi la testare
    set_fake_input("5\n8\n2022\n");
//verifica daca data este formatata corect in functie in baza citirii
    char* data = citire_data_valida();
    if (strcmp("05-08-2022", data)==0)
    	return 1;
    else 
    	return 0;
}

int test_introd_tranz() {
    //setam un input fals pe care sa-l putem folosi la testare
    set_fake_input("venit\nTestDescription\n50.5\n12\n12\n2022\n");

    int initial_nt = nt;  // se salveaza valoarea initiala a lui nt

    introd_tranz();
int nr=0,nrd=0;
    
    if(strcmp("venit", v[nt].tip)==0)
     nr=1;
     if(strcmp("TestDescription", v[nt].descriere)==0)
     nrd=1;
     // verifica daca numarul de tranzactii a fost incrementat cu 1
     // verifica datele ultimei tranzactii adaugat in vectorul v de tranzactii
    if((initial_nt + 1== nt)&&nr&&nrd&&(50.5== v[nt].suma))
    return 1;
else
return 0;
}*/

int test_calc_bal() {
    // Assuming v is a global array or structure for storing transactions
    // You might need to initialize it before running this test

    // Assuming nt is a global variable representing the number of transactions
    // You might need to initialize it before running this test

    // se adauga tranzactii de test(pentru aceasta functie, descrierea si data sunt irelevante deci nu este nevoie sa 
    //le initializam pentr v[1], v[2] si v[3]
    strcpy(v[1].tip, "venit");
    v[1].suma = 100.0;

    strcpy(v[2].tip, "tranzactie");
    v[2].suma = 50.0;

    strcpy(v[3].tip, "tranzactie");
    v[3].suma = 30.0;

    nt=3;//ne asiguram ca lungimea vectorului este corecta din moment ce am adaugat tranzactiile manual

    // Calculeaza balanta
    double balance = calc_bal();

    // Balanta asteptata este +100.0 (venit) - 50.0 (tranzactie) - 30.0 (tranzactie) = 20.0
    if (20.0== balance)
    return 1;
    else
    return 0;
}

int main()
{
    int ui;
    int finished=0;
        
    int ok=0;
    if(test_dateToString()==1&&test_calc_bal()==1)//&&test_citire_data_valida()==1&&test_introd_tranz()==1&&test_read_tip()
    	printf("testare efectuata cu succes!\n");
    else
    	printf("ceva nu functioneaza!\n");
    nt=0;
    while(finished==0)
    {
        printf("Introduceti optiunea dorita:\n");
        printf("1. Calculeaza BALANTA\n");
        printf("2. Afiseaza TRANZACTII anterioare\n");
        printf("3. Afiseaza EXTRASUL de cont pentru perioada dorita\n");
        printf("4. Introduceti TRANZACTIE\n");
        printf("5. SALVEAZA informatiile\n");
        printf("6. IMPORTA informatii\n");
        printf("7. IESIRE\n");
        scanf("%d",&ui);
        switch(ui)
        {
        case 1:
            calc_bal();
            printf("Balanta contului este: %f\n",calc_bal());
            break;
        case 2:
            afis_tranzactii();
            break;
        case 3:
            	afis_e_timp();
            break;
        case 4:
            introd_tranz();
            break;
        case 5:
            	salveaza();
            break;
        case 6:
            	importa();
            break;
        case 7:
            return 0;
        default:
            printf("Nu ati ales o optiune valida, pentru a continua apasati o tasta valida.\n");
        }
        printf("\n");
    }
    return 0;
}



