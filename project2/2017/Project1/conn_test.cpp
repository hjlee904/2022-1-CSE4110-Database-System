#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "mysql.h"

#pragma comment(lib, "libmysql.lib")

const char* host = "localhost";
const char* user = "root";
const char* pw = "2017db";
const char* db = "db";

int main(void) {

	MYSQL* connection = NULL;
	MYSQL conn;
	MYSQL_RES* sql_result;
	MYSQL_ROW sql_row;

	if (mysql_init(&conn) == NULL)
		printf("mysql_init() error!");

	connection = mysql_real_connect(&conn, host, user, pw, db, 3306, (const char*)NULL, 0);
	if (connection == NULL)
	{
		printf("%d ERROR : %s\n", mysql_errno(&conn), mysql_error(&conn));
		return 1;
	}

	else
	{
		printf("Connection Succeed\n");

		if (mysql_select_db(&conn, db))
		{
			printf("%d ERROR : %s\n", mysql_errno(&conn), mysql_error(&conn));
			return 1;
		}
		int num_fields;
		
		//const char* query = "select * from student";
		int state = 1;

		//state = mysql_query(connection, query);
		if (state == 0)
		{
			//sql_result = mysql_store_result(connection);
			//while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
			//{
			//	printf("%s %s %s %s\n", sql_row[0], sql_row[1], sql_row[2], sql_row[3]);
			//}
			//mysql_free_result(sql_result);
		}
		else if (state == 1)
		{
			FILE* fp;
			char str[500];

			// txt파일 읽어오기
			fp = fopen("2017.txt", "r");
			if (fp == NULL) {
				exit(1);
			}

			// 한 줄씩 읽기
			for (int i = 0; i < 79; i++) {
				fgets(str, sizeof(str), fp);
				mysql_query(connection, str);
				//printf("%d ERROR : %s\n", mysql_errno(&conn), mysql_error(&conn));
			}

			/*
			sql_result = mysql_use_result(connection);
			num_fields = mysql_num_fields(sql_result);
			while ((sql_row = mysql_fetch_row(sql_result)))
			{
				for (int i = 0; i < num_fields; i++)
				{
					printf("%s ", sql_row[i]);
				}
				printf(" ");
			}*/
			
			int ty, ty2, kk, fl = 1;
			while (fl) {
				printf("\n\n");
				printf("------- SELECT QUERY TYPES -------\n\n");
				printf("\t1. TYPE 1\n");
				printf("\t2. TYPE 2\n");
				printf("\t3. TYPE 3\n");
				printf("\t4. TYPE 4\n");
				printf("\t5. TYPE 5\n");
				printf("\t6. TYPE 6\n");
				printf("\t7. TYPE 7\n");
				printf("\t0. QUIT\n");
				printf("----------------------------------\n");

				scanf("%d", &ty);
				switch (ty) {
				case 1:
					printf("\n\n");
					printf("** Assume the package shipped by USPS with tracking number X is reported to	have been destroyed in an accident.Find the contact information for the customer.**\n");
					/*printf("Which K? : \n");
					scanf("%d", &kk);
					mysql_query(connection, "select T.phone from customer as T, ship as F where F.shipcom='USPS' and F.trnum='$kk' and F.cID=T.cID");
					sql_result = mysql_use_result(connection);
					num_fields = mysql_num_fields(sql_result);
					while ((sql_row = mysql_fetch_row(sql_result)))
					{
						for (int i = 0; i < num_fields; i++)
						{
							printf("%s ", sql_row[i]);
						}
						printf(" ");
					}*/

					printf("\n\n");
					printf("---- Subtypes in TYPE 1 ----\n\n");
					printf("1. TYPE 1-1\n");

					
					scanf("%d", &ty2);
					switch (ty2) {
					case 1:
						printf("---- TYPE 1-1 ----\n\n");
						printf("** Then find the contents of that shipment and create a new shipment of replacement items. **\n");
						break;
					case 0:
						fl = 0;
						//exit(0);
						break;
					}
					break;

				case 2:
					printf("\n\n");
					printf("** Find the customer who has bought the most (by price) in the past year. **\n");
					/*mysql_query(connection, "with totsum(cID, value) as (select cID, sum(price) from ship group by cID) select cID from totsum where value=max(value)");
					printf("%d ERROR : %s\n", mysql_errno(&conn), mysql_error(&conn));
					sql_result = mysql_use_result(connection);
					num_fields = mysql_num_fields(sql_result);
					while ((sql_row = mysql_fetch_row(sql_result)))
					{
						for (int i = 0; i < num_fields; i++)
						{
							printf("%s ", sql_row[i]);
						}
						printf(" ");
					}*/


					printf("\n\n");
					printf("---- Subtypes in TYPE 2 ----\n\n");
					printf("1. TYPE 2-1\n");

					scanf("%d", &ty2);
					switch (ty2) {
					case 1:
						printf("---- TYPE 2-1 ----\n\n");
						printf("** Then f ind the product that the customer bought the most. **\n");
						break;

					case 0:
						fl = 0;
						break;
					}
					break;

				case 3:
					printf("\n\n");
					printf("** Find all products sold in the past year. **\n");
					mysql_query(connection, "select distinct pID from ship where orddate>20210100 and orddate<20211232");
					sql_result = mysql_use_result(connection);
					num_fields = mysql_num_fields(sql_result);
					while ((sql_row = mysql_fetch_row(sql_result)))
					{
						for (int i = 0; i < num_fields; i++)
						{
							printf("%s ", sql_row[i]);
						}
						printf(" ");
					}

					printf("\n\n");
					printf("---- Subtypes in TYPE 3 ----\n\n");
					printf("1. TYPE 3-1\n");
					printf("2. TYPE 3-2\n");

					scanf("%d", &ty2);
					switch (ty2) {
					case 1:
						printf("---- TYPE 3-1 ----\n\n");
						printf("** Then f ind the top k products by dollar amount sold. **\n");
						printf("Which K? : \n");
						scanf("%d", &kk);
						break;

					case 2:
						printf("---- TYPE 3-2 ----\n\n");
						printf("** And then find the top 10% products by dollar amount sold. **\n");
						break;

					case 0:
						fl = 0;
						break;
					}
					break;

				case 4:
					printf("\n\n");
					printf("** Find all products by unit sales in the past year. **\n");
					

					printf("\n\n");
					printf("---- Subtypes in TYPE 4 ----\n\n");
					printf("1. TYPE 4-1\n");
					printf("2. TYPE 4-2\n");
					scanf("%d", &ty2);
					switch (ty2) {
					case 1:
						printf("---- TYPE 4-1 ----\n\n");
						printf("** Then find the top k products by unit sales. **\n");
						break;

					case 2:
						printf("---- TYPE 4-2 ----\n\n");
						printf("** And then find the top 10% products by unit sales. **\n");
						break;

					case 0:
						fl = 0;
						break;
					}
					break;

				case 5:
					printf("\n\n");
					printf("---- TYPE 5 ----\n\n");
					printf("** Find those products that are out of stock at every store in California. **\n");
					mysql_query(connection, "select pID from inven where store='California' and num=0");
					sql_result = mysql_use_result(connection);
					num_fields = mysql_num_fields(sql_result);
					while ((sql_row = mysql_fetch_row(sql_result)))
					{
						for (int i = 0; i < num_fields; i++)
						{
							printf("%s ", sql_row[i]);
						}
						printf(" ");
					}
					break;

				case 6:
					printf("\n\n");
					printf("---- TYPE 6 ----\n\n");
					printf("** Find those packages that were not delivered within the promised time. **\n");
					mysql_query(connection, "select trnum from ship where prodate<arrdate" );
					sql_result = mysql_use_result(connection);
					num_fields = mysql_num_fields(sql_result);
					while ((sql_row = mysql_fetch_row(sql_result)))
					{
						for (int i = 0; i < num_fields; i++)
						{
							printf("%s ", sql_row[i]);
						}
						printf(" ");
					}
					break;

				case 7:
					printf("\n\n");
					printf("---- TYPE 7 ----\n\n");
					printf("** Generate the bill for each customer for the past month. **\n");
					/*mysql_query(connection, "select sum(price) from ship natural join product where group by pID");
					sql_result = mysql_use_result(connection);
					num_fields = mysql_num_fields(sql_result);
					while ((sql_row = mysql_fetch_row(sql_result)))
					{
						for (int i = 0; i < num_fields; i++)
						{
							printf("%s ", sql_row[i]);
						}
						printf(" ");
					}*/
					break;

				case 0:
					fl = 0;
					//exit(0);
					break;

				}
				
			}

			for (int i = 0; i < 8; i++) {
				fgets(str, sizeof(str), fp);
				mysql_query(connection, str);
				//printf("%d ERROR : %s\n", mysql_errno(&conn), mysql_error(&conn));
			}

			fclose(fp);
			return 0;

		}
		
		mysql_close(connection);
	}
	
	return 0;
}
