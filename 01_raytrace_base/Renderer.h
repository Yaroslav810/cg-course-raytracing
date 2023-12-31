#pragma once

class CFrameBuffer;
class CScene;

/*
	����� CRenderer, ����������� ������������ ����� � ������ �����.
	������ �� ���������� ����������� � ������ ����� ����������� �
	��������� ������, ���� �� ��������� ������ ��������� ����������
*/
class CRenderer
{
public:
	~CRenderer(void);

	// ����������� �� � ������ ������ ���������� ����������� � ������ �����?
	bool IsRendering() const;

	/*
		�������� � ��������� ���������� ������:
			renderedChunks - ���������� ������������ ������ �����������
			totalChunks - ����� ���������� ������ �����������
		������������ ��������:
			true - ����������� ��������� ���������
			false - ����������� ��������� �� ���������
	*/
	bool GetProgress(unsigned& renderedChunks, unsigned& totalChunks) const;

	/*
		��������� ������� ����� ��� ������������ ����� � �������� ������ �����
		���������� true, ���� ����� ��� ������� � false, ���� ����� ������� �� ���,
		�.�. �� ����������� ������� �������� �� ���������� ����������� � ������ �����
	*/
	bool Render(CFrameBuffer& frameBuffer);

	/*
		��������� �������������� ��������� �������� ���������� �����������.
		������ ����� ������� �������� �� ������ ������������ ��������, ������������ ������� CRenderer,
		���� �� ������ �� ������ ����������� ���������� ����������� � ������ �����
	*/
	void Stop();

private:
	/*
		������������ �����, ����������� � ������� ������
	*/
	void RenderFrame(CFrameBuffer& frameBuffer);

	// ������������� ���������������� ������� ���� � ���, ��� ���� ���������� �����������
	// ���������� true, ���� �������� ����� ����������, � false, ���� ���
	bool SetRendering(bool rendering);

	// ������������� ����, ���������� �������� ������ � ������������� ���������
	// ���������� true, ���� �������� ����� ����������, � false, ���� ���
	bool SetStopping(bool stopping);

	// ���������� �� ����, ���������� � ������������� ���������� ������
	bool IsStopping() const;

	/*
		��������� ���� ������� ������ ����� � ����������� (x, y) 
		������ ����� �������� frameWidth * frameHeight
	*/
	uint32_t CalculatePixelColor(int x, int y, unsigned frameWidth, unsigned frameHeight)const;

private:
	// �����, � ������� ����������� ���������� �����������
	std::jthread m_thread;

	// ������� ��� ����������� ������� � ���������� m_totalChunks � m_renderedChunks
	mutable std::mutex m_mutex;

	// ���� �� � ������ ������ ���������� �����������?
	std::atomic_bool m_rendering{ false };

	// ������ �������� ������ � ������������� ���������� ������
	std::atomic_bool m_stopping{ false };

	// ����� ���������� ������ ����������� (��� ���������� ���������)
	std::atomic_uint32_t m_totalChunks{ 0 };

	// ���������� ������������ ������ ����������� (��� ���������� ���������)
	std::atomic_uint32_t m_renderedChunks{ 0 };
};
