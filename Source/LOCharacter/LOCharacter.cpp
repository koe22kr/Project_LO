// Fill out your copyright notice in the Description page of Project Settings.


#include "LOCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/InputComponent.h"
#include "Components/CapsuleComponent.h"
#include "LOAnimInstance.h"
// Sets default values


IMPLEMENT_MODULE(FDefaultModuleImpl, LOCharacter);

ALOCharacter::ALOCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GetCapsuleComponent()->InitCapsuleSize(42.0f, 96.0f);

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 300.0f;
	SpringArm->bUsePawnControlRotation = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false;

	GetMesh()->SetRelativeLocation(FVector(0.f, 0.0f, -95.f));

	bIsAiming = false;

}

// Called when the game starts or when spawned
void ALOCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ALOCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ALOCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAction("Aiming", IE_Pressed, this, &ALOCharacter::Aiming);
	PlayerInputComponent->BindAction("Aiming", IE_Released, this, &ALOCharacter::StopAiming);
	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &ALOCharacter::Attack);


	PlayerInputComponent->BindAxis("MoveForward", this, &ALOCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ALOCharacter::MoveRight);
	PlayerInputComponent->BindAxis("LookUp", this, &ALOCharacter::LookUp);
	PlayerInputComponent->BindAxis("Turn", this, &ALOCharacter::Turn);

}
void ALOCharacter::Attack()
{
	auto AnimInstance = Cast<ULOAnimInstance>(GetMesh()->GetAnimInstance());
	if (AnimInstance == nullptr)
	{
		return;
	}
	AnimInstance->PlayAttackMontage();
}

void ALOCharacter::Aiming()
{
	this->bIsAiming = true;

}
void ALOCharacter::StopAiming()
{
	this->bIsAiming = false;

}
void ALOCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}

}
void ALOCharacter::MoveRight(float Value)
{

	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}
void ALOCharacter::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}
void ALOCharacter::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void ALOCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
}
