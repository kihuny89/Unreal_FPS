// Copyright Epic Games, Inc. All Rights Reserved.


#include "CGameMode.h"
#include "Global.h"

ACGameMode::ACGameMode()
{
	//DefaultPawnClass : �⺻ �÷��̾� Ŭ������ �Է¹��� ����
	//TSubclassOf<APawn>�� ���� ��ӹ��� ���� Ŭ������ Ÿ���� �Է�

	//Blueprint'/Game/BP_CPlayer.BP_CPlayer'
	//�������Ʈ�� Ŭ����Ÿ���� ������ _C�� �� �ٿ���� �Ѵ�.
	/*ConstructorHelpers::FClassFinder<APawn> pawn(L"Blueprint'/Game/BP_CPlayer.BP_CPlayer_C'");

	if (pawn.Succeeded())
		pawn.Class;*/

	//���۽��� ������ ����
	CHelpers::GetClass<APawn>(&DefaultPawnClass, "Blueprint'/Game/BP_CPlayer.BP_CPlayer_C'");


}