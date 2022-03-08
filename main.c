#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#define MAX_DRINK 300
#define MAX_AMERICANO 100
#define MAX_LATTE 100
#define MAX_MOCHA 100
#define AMERICANO 1000
#define LATTE 1500
#define MOCHA 2000
#define ANGEL 1004 // �����ں�й�ȣ



struct COFFEE_MACHINE{
    int no;
    int americano;
    int latte;
    int mocha;
    int pay;
    int total;
    int inventory;

};

typedef struct COFFEE_MACHINE COFFEE_t;
void customer_mode(COFFEE_t *coffee);
void supervisor_mode(COFFEE_t *coffee);
void payment_americano(COFFEE_t *coffee);
void pay_cash_americano(COFFEE_t *coffee);
void pay_card(COFFEE_t *coffee);
void payment_latte(COFFEE_t *coffee);
void pay_cash_latte(COFFEE_t *coffee);
void payment_mocha(COFFEE_t *coffee);
void pay_cash_mocha(COFFEE_t *coffee);
void drink_stock();
void drink_sale_proceeds();


int main()
{
    COFFEE_t coffee [MAX_DRINK];
    int flag = 0;
    int service = 0;

    while(1){
        system("cls");
        fflush(stdin);
        puts("�ȳ��ϼ���. Ŀ�����Ǳ� �Դϴ�. �ʿ��Ͻ� ���� ��带 �������ּ���. \n");
        puts("1. ����� \t 2. �����ڸ�� \t 3. ������ \n");

        printf("�ʿ��� ���� : ");
        scanf("%d",&service);

        switch(service){

            case 1 :
                customer_mode(coffee);
                getchar();
                break;
            case 2 :
                supervisor_mode(coffee);
                getchar();
                //system("cls");
                break;
            case 3 :
                puts("Ŀ�����Ǳ⸦ �����մϴ�.");
                getchar();
                return;
            default : printf("�߸� �����̽��ϴ�.(1~2�� �����ʿ�)\n");
        }//end of switch case
    }//end of while
return 0;
}


// �����
void customer_mode(COFFEE_t *coffee){
    int flag = 0;
    int drink = 0;
    int americano = AMERICANO;
    int latte = LATTE;
    int mocha = MOCHA;

    while(!flag){

        system("cls");
        printf("-------------------------------------------------------------------------\n");
        printf("                      Ŀ   ��   ��   ��   ��   ��   ��                   \n");
        printf("-------------------------------------------------------------------------\n");
        printf("  1. americano:1,000�� 2. latte:1,500�� 3. mocha:2,000�� 4. ���ἱ����� \n");
        printf("-------------------------------------------------------------------------\n");

        printf("���Ͻô� ���Ḧ �����ϼ���: ");
        scanf("%d",&drink);

            switch(drink){
                case 1 :
                    printf("americano %d�� ����\n",americano);
                    payment_americano(coffee);
                    getchar();
                    getchar();
                    //system("cls");
                    break;
                 case 2 :
                    printf("latte %d�� ����\n",latte);
                    payment_latte(coffee);
                    getchar();
                    getchar();
                    //system("cls");
                    break;
                case 3 :
                    printf("mocha %d�� ����\n",mocha);
                    payment_mocha(coffee);
                    getchar();
                    getchar();
                    break;
                    //system("cls");
                case 4 :
                    flag = 1;
                    puts("���ἱ�� ���. �ʱ���� ���ư��ϴ�.");
                    getchar();
                    break;
                default :
                    getchar();
                    printf("�߸� �����̽��ϴ�.(���� �� 1~4�� �ٽü��� ���ּ���.)\n");
                    getchar();
            }
        } //end of while
return ;
}


//�����ڸ��
void supervisor_mode(COFFEE_t *coffee){
    int password = 0;
    int flag = 0;
    int check_point = 0;

    while(1){
    printf("Ŀ�����Ǳ� ������й�ȣ�� �Է����ּ���: ");
    scanf("%d",&password);
        if(password == ANGEL){
            puts("�����ڸ�带 �����մϴ�.");
            getchar();
            getchar();
            break;
        }else{
            puts("��й�ȣ�� Ʋ�Ƚ��ϴ�. �ٽ� �Է����ּ���.");
            continue;
        }
    }// end of while

    while(!flag){
        system("cls");
        printf("-------------------------------------------------------------------------\n");
        printf("              ��        ��       ��       ��        ��                   \n");
        printf("-------------------------------------------------------------------------\n");
        printf("1. ���� ��� Ȯ�� \n");
        printf("2. ���� �Ǹűݾ� Ȯ�� \n");
        printf("3. ������ �޴� ���� \n");
        printf("-------------------------------------------------------------------------\n");

        printf("Ȯ���� �޴��� �����ϼ���: ");
        scanf("%d",&check_point);

        switch(check_point){
            case 1:
                printf("������� Ȯ��â �Դϴ�. \n");
                drink_stock();
                getchar();
                getchar();
                break;
            case 2:
                printf("���� �Ǹűݾ� Ȯ��â �Դϴ�. \n");
                drink_sale_proceeds();
                getchar();
                getchar();
                break;
            case 3:
                puts("������ �޴� ���� �����ϼ̽��ϴ�. �ʱ���� ���ư��ϴ�.");
                flag=1;
                getchar();
                break;
                default : printf("�߸� �����̽��ϴ�.(1~3�� �����ʿ�)\n");
        }
    } // end of while
return;
}


//�Ƹ޸�ī�� �������
void payment_americano(COFFEE_t *coffee){
    int flag = 0;
    int pay = 0;
    int i = 0;

    while(!flag){
        printf("���� ���Ž� ��������� �����ϼ��� 1.���� 2.ī�� 3.���: ");
        scanf("%d",&pay);

        switch(pay){
            case 1:
                pay_cash_americano(coffee);
                getchar();
                getchar();
                printf("���ݰ����� �Ϸ�Ǿ����ϴ�.\n");
                flag = 1;
                break;
            case 2:
                pay_card(coffee);
                getchar();
                getchar();
                printf("ī������� �Ϸ�Ǿ����ϴ�..\n");
                flag = 1;
                break;
            case 3:
                printf("������ ����մϴ�.\n");
                getchar();
                flag = 1;
                break;
            default: printf("�߸� �����̽��ϴ�. (1~3�� �����ʿ�)\n");
        }
    }
    return;
}
//�� �������
void payment_latte(COFFEE_t *coffee){
    int flag = 0;
    int pay = 0;

    while(!flag){

        printf("���� ���Ž� ��������� �����ϼ��� 1.���� 2.ī�� 3.���: ");
        scanf("%d",&pay);

        switch(pay){
            case 1:
                pay_cash_latte(coffee);
                getchar();
                getchar();
                printf("���ݰ����� �Ϸ�Ǿ����ϴ�.\n");
                flag = 1;
                break;
            case 2:
                pay_card(coffee);
                getchar();
                getchar();
                printf("ī������� �Ϸ�Ǿ����ϴ�..\n");
                flag = 1;
                break;
            case 3:
                flag = 1;
                printf("������ ����մϴ�.\n");
                getchar();
                break;
            default: printf("�߸� �����̽��ϴ�. (1~3�� �����ʿ�)\n");
        }
    }
    return;
}
//��ī �������
void payment_mocha(COFFEE_t *coffee){
    int flag = 0;
    int pay = 0;

    while(!flag){

        printf("���� ���Ž� ��������� �����ϼ��� 1.���� 2.ī�� 3.���: ");
        scanf("%d",&pay);

        switch(pay){
            case 1:
                pay_cash_mocha(coffee);
                getchar();
                getchar();
                printf("���ݰ����� �Ϸ�Ǿ����ϴ�.\n");
                flag = 1;
                break;
            case 2:
                pay_card(coffee);
                getchar();
                getchar();
                printf("ī������� �Ϸ�Ǿ����ϴ�..\n");
                flag = 1;
                break;
            case 3:
                flag = 1;
                printf("������ ����մϴ�.\n");
                getchar();
                break;
            default: printf("�߸� �����̽��ϴ�. (1~3�� �����ʿ�)\n");
        }
    }
    return;
}

//���� ���ý�
void pay_cash_americano(COFFEE_t *coffee){
    int cash = 0;
    int sum = 0;
    while(1){
        printf("������ �־��ּ��� :");

        scanf("%d",&cash);
        sum += cash;
        if(sum > AMERICANO){
            printf("�Ž������� %d ���Դϴ�. \n",sum-AMERICANO);
            break;
        }else if(sum < AMERICANO){
            printf("�ݾ��� �����մϴ�. %d���� �� �־��ּ���. \n",AMERICANO-sum);
            continue;
        }else{
            printf("Ŀ�Ǹ� �̰ڽ��ϴ�\n");
            break;
        }


    }//end of while


return;
}

void pay_cash_latte(COFFEE_t *coffee){
    int cash = 0;
    int sum = 0;
    while(1){
        printf("������ �־��ּ��� :");

        scanf("%d",&cash);
        sum += cash;
        if(sum > LATTE){
            printf("�Ž������� %d ���Դϴ�. \n",sum-LATTE);
            break;
        }else if(sum < LATTE){
            printf("�ݾ��� �����մϴ�. %d���� �� �־��ּ���. \n",LATTE-sum);
            continue;
        }else{
            printf("Ŀ�Ǹ� �̰ڽ��ϴ�\n");
            break;
        }


    }//end of while


return;
}

void pay_cash_mocha(COFFEE_t *coffee){
    int cash = 0;
    int sum = 0;
    while(1){
        printf("������ �־��ּ��� :");

        scanf("%d",&cash);
        sum += cash;
        if(sum > MOCHA){
            printf("�Ž������� %d ���Դϴ�. \n",sum-MOCHA);
            break;
        }else if(sum < MOCHA){
            printf("�ݾ��� �����մϴ�. %d���� �� �־��ּ���. \n",MOCHA-sum);
            continue;
        }else{
            printf("Ŀ�Ǹ� �̰ڽ��ϴ�\n");
            break;
        }


    }//end of while


return;
}

//ī�� ���ý�
void pay_card(COFFEE_t *coffee){
    printf("ī������� �����ϼ̽��ϴ�.\n");
    printf("������ �������̿��� ī�带 �������� ��ø� ��ٷ��ּ���...");
    getchar();
return;
}

//������� Ȯ��
void drink_stock(){

    int sell_americano = 0;
    int sell_latte = 0;
    int sell_mocha = 0;
    int total_drink = 0;

    //�Ƹ޸�ī�� ��� Ȯ��
    while(1){
        printf("americano �Ǹ� ������ �־��ּ��� :");
        scanf("%d",&sell_americano);
        if(sell_americano < MAX_AMERICANO){
            printf("���� ���� americano ���� %d�� �Դϴ�.\n",MAX_AMERICANO-sell_americano);
            break;
        }else if (sell_americano == MAX_AMERICANO){
            printf("���� ���� americano ���� %d�� �Դϴ�. ���Ḧ ���� ä���ּ���.\n",MAX_AMERICANO-sell_americano);
            break;
        }else{
            printf("������ ���� �ʽ��ϴ�. �ٽ� Ȯ�����ּ���\n");
            continue;
        }
    }// end of while-americano

    //�� ���Ȯ��
    while(1){
        printf("latte �Ǹ� ������ �־��ּ��� :");
        scanf("%d",&sell_latte);
        if(sell_latte < MAX_LATTE){
            printf("���� ���� latte ���� %d�� �Դϴ�.\n",MAX_LATTE-sell_latte);
            break;
        }else if (sell_latte == MAX_LATTE){
            printf("���� ���� latte ���� %d�� �Դϴ�. ���Ḧ ���� ä���ּ���.\n",MAX_LATTE-sell_latte);
            break;
        }else{
            printf("������ ���� �ʽ��ϴ�. �ٽ� Ȯ�����ּ���\n");
            continue;
        }
    }// end of while

    //��ī ���Ȯ��
    while(1){
        printf("mocha �Ǹ� ������ �־��ּ��� :");
        scanf("%d",&sell_mocha);
        if(sell_mocha < MAX_MOCHA){
            printf("���� ���� mocha ���� %d�� �Դϴ�.\n",MAX_MOCHA-sell_mocha);
            break;
        }else if (sell_mocha == MAX_MOCHA){
            printf("���� ���� mocha ���� %d�� �Դϴ�. ���Ḧ ���� ä���ּ���.\n",MAX_MOCHA-sell_mocha);
            break;
        }else{
            printf("������ ���� �ʽ��ϴ�. �ٽ� Ȯ�����ּ���\n");
            continue;
        }
    }// end of while

        printf("\n");
        total_drink = sell_americano + sell_latte + sell_mocha;
        printf("������ �� ���� %d����...\t americano %d��, latte %d��, mocha %d�� �Դϴ�. \n" ,
               MAX_DRINK-total_drink, MAX_AMERICANO-sell_americano, MAX_LATTE-sell_latte, MAX_MOCHA-sell_mocha);

return;
}


//�����Ǹűݾ� Ȯ��
void drink_sale_proceeds(){
    int sell_americano = 0;
    int sell_latte = 0;
    int sell_mocha = 0;
    int total_drink = 0;
    int total_americano = 0;
    int total_latte = 0;
    int total_mocha = 0;

    while(1){
        printf("���� �Ǹ��� americano ���� :",sell_americano);
        scanf("%d",&sell_americano);
        if(sell_americano > MAX_AMERICANO){
            printf("�Ǹż��� �ٽ� �Է����ּ���.");
            continue;
        }break;
    }

    while(1){
        printf("���� �Ǹ��� latte ���� :",sell_latte);
        scanf("%d",&sell_latte);
        if(sell_latte > MAX_LATTE){
            printf("�Ǹż��� �ٽ� �Է����ּ���.");
            continue;
        }break;
    }

    while(1){
        printf("���� �Ǹ��� mocha ���� :",sell_mocha);
        scanf("%d",&sell_mocha);
        if(sell_mocha > MAX_MOCHA){
            printf("�Ǹż��� �ٽ� �Է����ּ���.");
            continue;
        }break;
    }

    total_americano = sell_americano*AMERICANO;
    total_latte = sell_latte*LATTE;
    total_mocha = sell_mocha*MOCHA;
    total_drink = total_americano + total_latte + total_mocha;

    printf("���� �Ǹűݾ��� americano %d�� ,latte %d��, mocha %d������ \t �� %d�� �Դϴ�. ",
           total_americano,total_latte,total_mocha, total_drink);

return;
}

