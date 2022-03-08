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
#define ANGEL 1004 // 관리자비밀번호



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
        puts("안녕하세요. 커피자판기 입니다. 필요하신 서비스 모드를 선택해주세요. \n");
        puts("1. 고객모드 \t 2. 관리자모드 \t 3. 종료모드 \n");

        printf("필요한 서비스 : ");
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
                puts("커피자판기를 종료합니다.");
                getchar();
                return;
            default : printf("잘못 누르셨습니다.(1~2번 선택필요)\n");
        }//end of switch case
    }//end of while
return 0;
}


// 고객모드
void customer_mode(COFFEE_t *coffee){
    int flag = 0;
    int drink = 0;
    int americano = AMERICANO;
    int latte = LATTE;
    int mocha = MOCHA;

    while(!flag){

        system("cls");
        printf("-------------------------------------------------------------------------\n");
        printf("                      커   피   자   판   기   메   뉴                   \n");
        printf("-------------------------------------------------------------------------\n");
        printf("  1. americano:1,000원 2. latte:1,500원 3. mocha:2,000원 4. 음료선택취소 \n");
        printf("-------------------------------------------------------------------------\n");

        printf("원하시는 음료를 선택하세요: ");
        scanf("%d",&drink);

            switch(drink){
                case 1 :
                    printf("americano %d원 선택\n",americano);
                    payment_americano(coffee);
                    getchar();
                    getchar();
                    //system("cls");
                    break;
                 case 2 :
                    printf("latte %d원 선택\n",latte);
                    payment_latte(coffee);
                    getchar();
                    getchar();
                    //system("cls");
                    break;
                case 3 :
                    printf("mocha %d원 선택\n",mocha);
                    payment_mocha(coffee);
                    getchar();
                    getchar();
                    break;
                    //system("cls");
                case 4 :
                    flag = 1;
                    puts("음료선택 취소. 초기모드로 돌아갑니다.");
                    getchar();
                    break;
                default :
                    getchar();
                    printf("잘못 누르셨습니다.(엔터 후 1~4번 다시선택 해주세요.)\n");
                    getchar();
            }
        } //end of while
return ;
}


//관리자모드
void supervisor_mode(COFFEE_t *coffee){
    int password = 0;
    int flag = 0;
    int check_point = 0;

    while(1){
    printf("커피자판기 관리비밀번호를 입력해주세요: ");
    scanf("%d",&password);
        if(password == ANGEL){
            puts("관리자모드를 실행합니다.");
            getchar();
            getchar();
            break;
        }else{
            puts("비밀번호가 틀렸습니다. 다시 입력해주세요.");
            continue;
        }
    }// end of while

    while(!flag){
        system("cls");
        printf("-------------------------------------------------------------------------\n");
        printf("              관        리       자       모        드                   \n");
        printf("-------------------------------------------------------------------------\n");
        printf("1. 음료 재고 확인 \n");
        printf("2. 음료 판매금액 확인 \n");
        printf("3. 관리자 메뉴 종료 \n");
        printf("-------------------------------------------------------------------------\n");

        printf("확인할 메뉴를 선택하세요: ");
        scanf("%d",&check_point);

        switch(check_point){
            case 1:
                printf("음료재고 확인창 입니다. \n");
                drink_stock();
                getchar();
                getchar();
                break;
            case 2:
                printf("음료 판매금액 확인창 입니다. \n");
                drink_sale_proceeds();
                getchar();
                getchar();
                break;
            case 3:
                puts("관리자 메뉴 종료 선택하셨습니다. 초기모드로 돌아갑니다.");
                flag=1;
                getchar();
                break;
                default : printf("잘못 누르셨습니다.(1~3번 선택필요)\n");
        }
    } // end of while
return;
}


//아메리카노 결제방식
void payment_americano(COFFEE_t *coffee){
    int flag = 0;
    int pay = 0;
    int i = 0;

    while(!flag){
        printf("음료 구매시 결제방식을 선택하세요 1.현금 2.카드 3.취소: ");
        scanf("%d",&pay);

        switch(pay){
            case 1:
                pay_cash_americano(coffee);
                getchar();
                getchar();
                printf("현금결제가 완료되었습니다.\n");
                flag = 1;
                break;
            case 2:
                pay_card(coffee);
                getchar();
                getchar();
                printf("카드결제가 완료되었습니다..\n");
                flag = 1;
                break;
            case 3:
                printf("결제를 취소합니다.\n");
                getchar();
                flag = 1;
                break;
            default: printf("잘못 누르셨습니다. (1~3번 선택필요)\n");
        }
    }
    return;
}
//라떼 결제방식
void payment_latte(COFFEE_t *coffee){
    int flag = 0;
    int pay = 0;

    while(!flag){

        printf("음료 구매시 결제방식을 선택하세요 1.현금 2.카드 3.취소: ");
        scanf("%d",&pay);

        switch(pay){
            case 1:
                pay_cash_latte(coffee);
                getchar();
                getchar();
                printf("현금결제가 완료되었습니다.\n");
                flag = 1;
                break;
            case 2:
                pay_card(coffee);
                getchar();
                getchar();
                printf("카드결제가 완료되었습니다..\n");
                flag = 1;
                break;
            case 3:
                flag = 1;
                printf("결제를 취소합니다.\n");
                getchar();
                break;
            default: printf("잘못 누르셨습니다. (1~3번 선택필요)\n");
        }
    }
    return;
}
//모카 결제방식
void payment_mocha(COFFEE_t *coffee){
    int flag = 0;
    int pay = 0;

    while(!flag){

        printf("음료 구매시 결제방식을 선택하세요 1.현금 2.카드 3.취소: ");
        scanf("%d",&pay);

        switch(pay){
            case 1:
                pay_cash_mocha(coffee);
                getchar();
                getchar();
                printf("현금결제가 완료되었습니다.\n");
                flag = 1;
                break;
            case 2:
                pay_card(coffee);
                getchar();
                getchar();
                printf("카드결제가 완료되었습니다..\n");
                flag = 1;
                break;
            case 3:
                flag = 1;
                printf("결제를 취소합니다.\n");
                getchar();
                break;
            default: printf("잘못 누르셨습니다. (1~3번 선택필요)\n");
        }
    }
    return;
}

//현금 선택시
void pay_cash_americano(COFFEE_t *coffee){
    int cash = 0;
    int sum = 0;
    while(1){
        printf("현금을 넣어주세요 :");

        scanf("%d",&cash);
        sum += cash;
        if(sum > AMERICANO){
            printf("거스름돈은 %d 원입니다. \n",sum-AMERICANO);
            break;
        }else if(sum < AMERICANO){
            printf("금액이 부족합니다. %d원을 더 넣어주세요. \n",AMERICANO-sum);
            continue;
        }else{
            printf("커피를 뽑겠습니다\n");
            break;
        }


    }//end of while


return;
}

void pay_cash_latte(COFFEE_t *coffee){
    int cash = 0;
    int sum = 0;
    while(1){
        printf("현금을 넣어주세요 :");

        scanf("%d",&cash);
        sum += cash;
        if(sum > LATTE){
            printf("거스름돈은 %d 원입니다. \n",sum-LATTE);
            break;
        }else if(sum < LATTE){
            printf("금액이 부족합니다. %d원을 더 넣어주세요. \n",LATTE-sum);
            continue;
        }else{
            printf("커피를 뽑겠습니다\n");
            break;
        }


    }//end of while


return;
}

void pay_cash_mocha(COFFEE_t *coffee){
    int cash = 0;
    int sum = 0;
    while(1){
        printf("현금을 넣어주세요 :");

        scanf("%d",&cash);
        sum += cash;
        if(sum > MOCHA){
            printf("거스름돈은 %d 원입니다. \n",sum-MOCHA);
            break;
        }else if(sum < MOCHA){
            printf("금액이 부족합니다. %d원을 더 넣어주세요. \n",MOCHA-sum);
            continue;
        }else{
            printf("커피를 뽑겠습니다\n");
            break;
        }


    }//end of while


return;
}

//카드 선택시
void pay_card(COFFEE_t *coffee){
    printf("카드결제를 선택하셨습니다.\n");
    printf("결제가 진행중이오니 카드를 빼지말고 잠시만 기다려주세요...");
    getchar();
return;
}

//음료재고 확인
void drink_stock(){

    int sell_americano = 0;
    int sell_latte = 0;
    int sell_mocha = 0;
    int total_drink = 0;

    //아메리카노 재고 확인
    while(1){
        printf("americano 판매 개수를 넣어주세요 :");
        scanf("%d",&sell_americano);
        if(sell_americano < MAX_AMERICANO){
            printf("현재 남은 americano 재고는 %d개 입니다.\n",MAX_AMERICANO-sell_americano);
            break;
        }else if (sell_americano == MAX_AMERICANO){
            printf("현재 남은 americano 재고는 %d개 입니다. 음료를 가득 채워주세요.\n",MAX_AMERICANO-sell_americano);
            break;
        }else{
            printf("수량이 맞지 않습니다. 다시 확인해주세요\n");
            continue;
        }
    }// end of while-americano

    //라떼 재고확인
    while(1){
        printf("latte 판매 개수를 넣어주세요 :");
        scanf("%d",&sell_latte);
        if(sell_latte < MAX_LATTE){
            printf("현재 남은 latte 재고는 %d개 입니다.\n",MAX_LATTE-sell_latte);
            break;
        }else if (sell_latte == MAX_LATTE){
            printf("현재 남은 latte 재고는 %d개 입니다. 음료를 가득 채워주세요.\n",MAX_LATTE-sell_latte);
            break;
        }else{
            printf("수량이 맞지 않습니다. 다시 확인해주세요\n");
            continue;
        }
    }// end of while

    //모카 재고확인
    while(1){
        printf("mocha 판매 개수를 넣어주세요 :");
        scanf("%d",&sell_mocha);
        if(sell_mocha < MAX_MOCHA){
            printf("현재 남은 mocha 재고는 %d개 입니다.\n",MAX_MOCHA-sell_mocha);
            break;
        }else if (sell_mocha == MAX_MOCHA){
            printf("현재 남은 mocha 재고는 %d개 입니다. 음료를 가득 채워주세요.\n",MAX_MOCHA-sell_mocha);
            break;
        }else{
            printf("수량이 맞지 않습니다. 다시 확인해주세요\n");
            continue;
        }
    }// end of while

        printf("\n");
        total_drink = sell_americano + sell_latte + sell_mocha;
        printf("음료의 총 재고는 %d개로...\t americano %d개, latte %d개, mocha %d개 입니다. \n" ,
               MAX_DRINK-total_drink, MAX_AMERICANO-sell_americano, MAX_LATTE-sell_latte, MAX_MOCHA-sell_mocha);

return;
}


//음료판매금액 확인
void drink_sale_proceeds(){
    int sell_americano = 0;
    int sell_latte = 0;
    int sell_mocha = 0;
    int total_drink = 0;
    int total_americano = 0;
    int total_latte = 0;
    int total_mocha = 0;

    while(1){
        printf("오늘 판매한 americano 수량 :",sell_americano);
        scanf("%d",&sell_americano);
        if(sell_americano > MAX_AMERICANO){
            printf("판매수량 다시 입력해주세요.");
            continue;
        }break;
    }

    while(1){
        printf("오늘 판매한 latte 수량 :",sell_latte);
        scanf("%d",&sell_latte);
        if(sell_latte > MAX_LATTE){
            printf("판매수량 다시 입력해주세요.");
            continue;
        }break;
    }

    while(1){
        printf("오늘 판매한 mocha 수량 :",sell_mocha);
        scanf("%d",&sell_mocha);
        if(sell_mocha > MAX_MOCHA){
            printf("판매수량 다시 입력해주세요.");
            continue;
        }break;
    }

    total_americano = sell_americano*AMERICANO;
    total_latte = sell_latte*LATTE;
    total_mocha = sell_mocha*MOCHA;
    total_drink = total_americano + total_latte + total_mocha;

    printf("당일 판매금액은 americano %d원 ,latte %d원, mocha %d원으로 \t 총 %d원 입니다. ",
           total_americano,total_latte,total_mocha, total_drink);

return;
}

