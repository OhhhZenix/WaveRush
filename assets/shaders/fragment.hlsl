struct PSInput
{
    float4 color : COLOR0;
};

float4 PSMain(PSInput input) : SV_Target0
{
    return input.color;
}
