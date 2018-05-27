#include "adress.h"
void menu()
{
    printf("===========服务菜单===========\n");
    printf("==============================\n");
    printf("          1.添加联系人\n");
    printf("          2.删除联系人\n");
    printf("          3.清空联系人\n");
    printf("          4.查找联系人\n");
    printf("          5.修改联系人\n");
    printf("          6.显示所有联系人\n");
    printf("          0.退出\n");
    printf("==============================\n");

}
void init_contacts(contacts *men)
{
    men->capacity = MAX;
    men->user_count = 0;
    men->person = (user *)malloc(sizeof(user)*MAX);
}
int _find(contacts *men)
{
    int i = 0;
    char name[NAME_LENGTH];
    printf("请输入名字：");
    scanf("%s",name);
    for(i = 0;i < men->user_count;i++)
    {
        if(strcmp(men->person[i].name,name) == 0)
        {
            return i;
        }
    }
    return -1;
}
int add_contacts(contacts *men)
{
    if(men == NULL)
    {
        return;
    }
    if(men->user_count == men->capacity)
    {
        user *tmp = (user *)realloc(men->person,(men->capacity +3)*sizeof(user));
        if(tmp == NULL)
        {
            printf("内存不足\n");
            return -1;
        }
        else
        {
            men->person = tmp;
            (men->capacity)+= 3;
            return 1;
        }
    }
    else
    {
        printf("请输入名字:");
        scanf("%s",men->person[men->user_count].name);
        printf("请输入性别:");
        scanf("%s",men->person[men->user_count].sex);
        printf("请输入年龄:");
        scanf("%s",men->person[men->user_count].age);
        printf("请输入电话:");
        scanf("%s",men->person[men->user_count].tele);
        printf("请输入地址:");
        scanf("%s",men->person[men->user_count].addr);
        printf("添加成功！\n");
        men->user_count++;
        return 1;
    }
}
void show_contacts(contacts *men)
{
    int i = 0;
    printf("%10s\t%4s\t%3s\t%13s\t%10s\n","姓名","性别","年龄","电话","地址");
    for(;i< men->user_count;i++)
    {
        printf("%10s\t%4s\t%3s\t%13s\t%10s\n",men->person[i].name,men->person[i].sex,
           men->person[i].age,men->person[i].tele,men->person[i].addr);
    }
    printf("\n");
}

//int find_contacts(contacts *men);
//int erase_contacts(contacts *men);
//int clear_contacts(contacts *men);
//int remove_contacts(contacts *men);
//void sort_contacts(contacts *men);
//void check(contacts *men);
//void testadd()
//{
//    HEADER;
//    menu();
//    contacts men;
//    int input;
//    printf("请输入数字编号\n");
//    scanf("%d",&input);
//    add_contacts(&men);
//    show_contacts(&men);
//}

int main()
{
    int input = 1;
    contacts user;
    init_contacts(&user);
//    contacts user = {0};
//    user.capacity = MAX;
//    user.user_count = 0;
//    user.person = (user *)malloc(sizeof(user)*MAX);
    if(user.person == NULL)
    {
        printf("内存不足\n");
        return;
    }
    else
    {
        menu();
        while(input)
        {
            printf("请输入数字编号\n");
            scanf("%d",&input);
            switch(input)
            {
            case ADD:
                add_contacts(&user);
                show_contacts(&user);
                menu();
                break;
            }
        }

    }
    free(user.person);
    user.person = NULL;
    return 0;
}
