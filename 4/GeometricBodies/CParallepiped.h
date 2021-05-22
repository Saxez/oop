#pragma once
#include "CBody.h"
class CParallepiped :
    public CBody
{
public:
    CParallepiped(double density, double width, double height, double depth);

    double GetWidth()  const;
    double GetHeight() const;
    double GetDepth()  const;
    double GetVolume() const override;

private:
    void AppendProperties(ostream& strm) const override;
    double m_width;
    double m_height;
    double m_depth;
};

