#pragma once

#include <Windows.h>

class KeyInput
{
public:
	// インスタンス作成
	static void CreateInstance()
	{
		DeleteInstance();

		s_instance = new KeyInput();
	}

	// インスタンス削除
	static void DeleteInstance()
	{
		if (s_instance != nullptr)
		{
			delete s_instance;
			s_instance = nullptr;
		}
	}

	static KeyInput& GetInstance() { return *s_instance; } // 唯一のインスタンスを取得
	static bool IsExist() { return s_instance != nullptr; }


	void Initialize() { ZeroMemory(m_keys, sizeof(m_keys)); }
    void OnKeyDown(WPARAM k) { if (k < 256) m_keys[k] = true; }
    void OnKeyUp(WPARAM k) { if (k < 256) m_keys[k] = false; }
    bool IsKeyDown(UINT8 vk) const { return m_keys[vk]; }

private:
	static KeyInput* s_instance; // インスタンス	
	
	bool m_keys[256]{};
};