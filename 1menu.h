static bool X1 = true;
static bool Bekabutton2 = true;
static bool openmenu;
static bool Bekar0 = true;

      if (Bekar0){

	   static bool logginIn = false;
static char s[64];
static bool isLogin = false;
static std::string err;
if (!isLogin) {
ImVec2 center = ImGui::GetMainViewport()->GetCenter();
ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
ImGui::SetNextWindowSize(ImVec2(370, 400));
ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 10.0f);
if (ImGui::Begin(OBFUSCATE(""), 0, ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar)) {
ImGui::PopStyleVar();
 //ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 10.0f); // Увеличиваем закругление
  //  ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 10.0f); // Закругляем края окна

    // Настройка фона окна
    
    
    ImVec2 windowPos = ImGui::GetWindowPos();
ImVec2 windowSize = ImGui::GetWindowSize();
ImDrawList* drawList = ImGui::GetWindowDrawList();
drawList->AddImage((ImTextureID)LogoPIC.textureId, windowPos, ImVec2(windowPos.x + windowSize.x, windowPos.y + windowSize.y));

//ImGui::PushStyleColor(ImGuiCol_Button,IM_COL32(210,24,17,200));

    ImGui::SetCursorPos({ 15, 30 });
    ImGui::TextColored(ImColor(255, 255, 255, 255), "    \n  \n \n \n \n  \n \n \n \n Paste your key...");
ImGui::Separator();
    // Поле ввода
    ImGui::SetCursorPos({ 60, 220 });
    ImGui::PushStyleColor(ImGuiCol_FrameBg, IM_COL32(50, 50, 50, 255));
    ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(200, 200, 200, 255));
    static char s[128] = "";
    ImGui::InputTextWithHint("##key", "", s, sizeof(s));
    ImGui::PopStyleColor(2); // Убираем стиль поля ввода
//ImGui::Separator();
    // Кнопка "Paste"
  //  ImGui::Separator();
    ImGui::SetCursorPos({ 55, 255 });
ImGui::Separator();
ImGui::SetCursorPos({ 30, 259 });
    if (ImGui::Button("Paste", ImVec2(150, 45))) {
        auto key = getClipboardText();
        strcpy(s, key.c_str());
    }
    ImGui::PopStyleColor(3); // Убираем стили кнопки
//ImGui::Separator();
    // Кнопка "Enter"
    ImGui::SameLine(); 
    if (ImGui::Button("Enter", ImVec2(150, 45))) {
        std::string err = Login(s);
        if (err == "OK") {
            isLogin = bValid && g_Auth == g_Token;
        }
    }
//ImGui::Separator();
            ImGui::SetCursorPos(ImVec2(120, 320));
            ImGuiTextURL("Telegram    Channel ", "https://t.me/terrible_pm"); //


    // Убираем стили окна
    ImGui::PopStyleColor();
    ImGui::PopStyleVar(2); // Убираем стиль закругления

    // Другие элементы управления можно добавлять ниже
    }
} else {

           BekaS = true;
           Bekar0 = false;
           openmenu = true;
            }
	}
if (openmenu){
ImGui::SetNextWindowPos(ImVec2(80, 60), ImGuiCond_FirstUseEver);
ImGui::SetNextWindowSize(ImVec2((float) glWidth * 0.1f, (float) glHeight * 0.2f), ImGuiCond_Once);
if (ImGui::Begin("**Cd", 0, ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoSavedSettings)){
ImGui::PushStyleColor(ImGuiCol_Button, {0,0,0,0});
ImGui::PushStyleColor(ImGuiCol_ButtonHovered, {0,0,0,0});
ImGui::PushStyleColor(ImGuiCol_ButtonActive, {0,0,0,0});
ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 0.0f);
if (ImGui::ImageButton((ImTextureID)Logo5.textureId, ImVec2(77, 77))){BekaS = !BekaS;}
ImGui::PopStyleColor(3);
ImGui::PopStyleVar(1);}

}



    if (BekaS){

 ImGuiViewport* viewport = ImGui::GetMainViewport();
    ImVec2 center = viewport->GetCenter();
    ImVec2 displaySize = viewport->Size; // Получаем размеры экрана
ImGui::PushStyleColor(ImGuiCol_WindowBg, IM_COL32(0, 0, 0, 230));
    // Устанавливаем размер окна
    ImGui::SetNextWindowSize(ImVec2(600, 538), ImGuiCond_Always); 

    // Проверяем, нужно ли сбросить slideY при открытии окна
    static float slideY = displaySize.y + 50.0f; // Начинаем ниже экрана
    static bool initialized = true; // Состояние инициализации

    // Сбрасываем slideY при открытии окна
    if (initialized) {
        slideY = displaySize.y + 50.0f; // Сбрасываем позицию для нового открытия
        initialized = false; // Устанавливаем как инициализированное
    }

    // Увеличиваем скорость анимации до 800.0f
    slideY -= io.DeltaTime * 990.0f; // Уменьшаем Y для подъема
    if (slideY < displaySize.y - 610) slideY = displaySize.y - 610; // Ограничение на конечное положение
    // Устанавливаем позицию окна
    ImGui::SetNextWindowPos(ImVec2(center.x - 300, slideY), ImGuiCond_Always); // Центруем по горизонтали с учетом ширины




    //ImGui::SetNextWindowSize(ImVec2(600, 538), ImGuiCond_Always);
    ImGui::Begin( "Menu",&BekaS, ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoTitleBar);
        std::string currentTime, date, dayOfWeek;
    GetCurrentTimeAndDate(currentTime, date, dayOfWeek);
ImGui::PushStyleColor(ImGuiCol_WindowBg, IM_COL32(0, 0, 0, 255));
ImGui::SetWindowFontScale(1.7);
ImGui::TextColored(ImColor(borderColor), " BEKA ENGINE"); 
ImGui::SetWindowFontScale(1.0);
ImGui::SameLine(); 
ImGui::TextColored(ImColor(255, 255, 255, 255), "                                   \n      ");
ImGui::SameLine(); 
ImGui::TextColored(ImColor(borderColor), " %s", currentTime.c_str()); 
ImGui::SameLine(); 
ImGui::TextColored(ImColor(borderColor), "|   %s", date.c_str());
    
    ImGui::SameLine(ImGui::GetWindowWidth() - 80);
    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0, 0, 0, 0));        
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0, 0, 0, 0.1f)); 
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0, 0, 0, 0.2f));  
        ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(0, 0));        
        ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 0.0f);             
    if (ImGui::Button("Close", ImVec2(90, 30))) {  BekaS = false; }
        ImGui::PopStyleVar(2);
        ImGui::PopStyleColor(3);
{
              ImGui::TextColored(ImColor(255, 255, 255, 255), "");
    ImGui::BeginChild("Sidebar", ImVec2(585, 70), true);
    {      
        ImGui::TextColored(ImColor(255, 255, 255, 255), "                  ");
        ImGui::SameLine();      
	    if(ImGui::BekaButton( "  Esp  ",  Settings::Tab == 1))
		Settings::Tab = 1;		
		ImGui::SameLine();      
        if(ImGui::BekaButton( " Aimbot ",  Settings::Tab == 2)) 
		Settings::Tab = 2;
		ImGui::SameLine();      
        if(ImGui::BekaButton( " Settings ",  Settings::Tab == 3)) 
  	    Settings::Tab = 3;
  	    ImGui::SameLine();      
	    if(ImGui::BekaButton( " Memory  ",  Settings::Tab == 4)) 
  	    Settings::Tab = 4;
    }ImGui::EndChild();
    
    if (Settings::Tab == 2) {
    ImGui::SetCursorPos(ImVec2(7.5, 150));
    ImGui::BeginChild("Aim", ImVec2(585, 70), true);{
    ImGui::TextColored(ImColor(255, 255, 255, 255), "                                                ");
    ImGui::SameLine();      
    if(ImGui::BekaaButton( " Aimbot ",  Beka::Tab == 1)) 
    Beka::Tab = 1;
    ImGui::SameLine();      
    ImGui::TextColored(ImColor(255, 255, 255, 255), "             ");
    ImGui::SameLine();      
    if(ImGui::BekaaButton( "SilentAim",  Beka::Tab == 2)) 
    Beka::Tab = 2;

    }ImGui::EndChild();
    
    if (Beka::Tab == 1) {
    ImGui::SetCursorPos(ImVec2(7.5, 230));
    ImGui::BeginChild("Aim2", ImVec2(585, 270), true);{ 
                        Config.AimBot.RecoilComparison = true;                  
                   Config.AimBot.VisCheck = true;
                        Config.AimBot.Recc = 1.0f;

    ImGui::BekaCheckbox("  Enable Aim",&Config.AimBot.Enable);       
    ImGui::BekaCheckbox("  IngoreKnocked", &Config.AimBot.IgnoreKnocked);
                    ImGui::SameLine();      
    ImGui::BekaCheckbox("  IngoreBot", &Config.AimBot.IgnoreBots);
                    ImGui::SameLine();
    ImGui::BekaCheckbox("  VisCheck", &Config.AimBot.VisCheck);
    ImGui::SliderFloat("Fov Size",&Config.AimBot.Cross,0.0f,200.0f);
    ImGui::SliderFloat("Meter ", &Config.Meter, 0.0f, 100.00f);

            }ImGui::EndChild();
            }
                if (Beka::Tab == 2) {
         ImGui::SetCursorPos(ImVec2(7.5, 230));
    ImGui::BeginChild("Bt2", ImVec2(585, 270), true);{
                        }ImGui::EndChild();
            }}
            
                        if (Settings::Tab == 3) {
                        ImGui::SetCursorPos(ImVec2(7.5, 150));
            ImGui::BeginChild("Settings", ImVec2(585, 350), true);
            {      
    
    ImGui::Text("Edit menu styles ");
    ImGui::ColorEdit4("Menu Color", (float*)&borderColor); 



    ImGui::GetStyle().Colors[ImGuiCol_Border] = ImColor(borderColor); 
            }ImGui::EndChild();              
            
            }
                        if (Settings::Tab == 4) {
                        ImGui::SetCursorPos(ImVec2(7.5, 150));
            ImGui::BeginChild("Memory ", ImVec2(585, 350), true);
            {      
            
            
            }ImGui::EndChild();                          
            }

            if (Settings::Tab == 1) {
            ImGui::SetCursorPos(ImVec2(7.5, 150));
            ImGui::BeginChild("esp", ImVec2(300, 180), true);
    {
                        ImGui::BekaCheckbox(u8"  Line", &Config.PlayerESP.Line);
                      	ImGui::BekaCheckbox(u8"  Health", &Config.PlayerESP.Health);
                        ImGui::BekaCheckbox(u8"  Name", &Config.PlayerESP.Name);
                       	ImGui::BekaCheckbox(u8"  Distance", &Config.PlayerESP.Distance);  
                       	
                       
                        

                }ImGui::EndChild();
                ImGui::SetCursorPos(ImVec2(310, 150));
                ImGui::BeginChild("esp2", ImVec2(285, 180), true);
                {
                ImGui::BekaCheckbox(u8"  Vehicle", &Config.PlayerESP.Vehicle);
			 //   ImGui::SameLine();
    		    ImGui::BekaCheckbox(u8"  Granade Alert", &Config.PlayerESP.Grenade);
                ImGui::BekaCheckbox(u8"  Enemy Weapon", &Config.PlayerESP.Weapon);
                ImGui::BekaCheckbox(u8"  Team Id", &Config.PlayerESP.TeamID);
			  	
                }ImGui::EndChild();
                ImGui::SetCursorPos(ImVec2(7.5, 340));
                ImGui::BeginChild("esp3", ImVec2(300, 160), true);
                {
                ImGui::BekaCheckbox(u8"  Hide Bot", &Config.PlayerESP.NoBot); 
                ImGui::BekaCheckbox(u8"  Hide Esp", &Config.OTHER.HIDEESP);                
                ImGui::BekaCheckbox(u8"  Skeleton", &Config.PlayerESP.Skeleton);     
                ImGui::BekaCheckbox(u8"  3D Box", &Config.PlayerESP.Box); 
                }ImGui::EndChild();                
                ImGui::SetCursorPos(ImVec2(310, 340));
                ImGui::BeginChild("esp4", ImVec2(285, 160), true);
                {  
			   		    ImGui::BekaCheckbox(u8"  360 Alert", &Config.PlayerESP.Alert);
                        ImGui::BekaCheckbox(u8"  LootBox", &Config.PlayerESP.LootBox);
                        ImGui::BekaCheckbox(u8"  Alert(Circle)", &Config.PlayerESP.ALPxAlert360);	
			   		    ImGui::BekaCheckbox(u8"  PC Health", &Config.PlayerESP.Alert180);
			    }ImGui::EndChild();                
                }
                ImGui::SetCursorPos(ImVec2(7.5, 510));
                ImGui::TextColored(ImColor(borderColor), "Key time EXP: ");
                ImGui::SetCursorPos(ImVec2(520, 510));
                ImGuiTextURL("Telegram", "https://t.me/terrible_pm"); // Отобразит текст "Telegram Channel" как ссылку
                

}


}

ImGui::End();
    ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());