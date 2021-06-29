#pragma once

namespace OGLE {
	struct FrameBufferSpecification 
	{
		uint32_t Width, Height;
		uint32_t Samples = 1;

		bool SwapChainTargets = false;
	};

	class FrameBuffer 
	{
	public:
		FrameBuffer(const FrameBufferSpecification& spec);
		~FrameBuffer();

		const FrameBufferSpecification& GetSpecification() const;
		void Invalidate();

		uint32_t GetColorAttachmentRendererID() const { return m_ColorAttachment; };

		static Ref<FrameBuffer> Create(const FrameBufferSpecification& spec);

		void Bind();
		void Unbind();
		void Resize(uint32_t width, uint32_t height);

	private:
		uint32_t m_RendererID;
		uint32_t m_ColorAttachment;
		uint32_t m_DepthAttachment;
		FrameBufferSpecification m_Specification;
	};
}