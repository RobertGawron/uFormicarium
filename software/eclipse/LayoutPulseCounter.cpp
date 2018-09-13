#include "LayoutPulseCounter.h"

LayoutPulseCounter::LayoutPulseCounter(DisplayDevice& display) : display(display)
{
}

void LayoutPulseCounter::draw(ISampleBuffer& data)
{
    display.clean();

    MeasurementHistory<int, 20> buffer;
    buffer.add(10);
    buffer.add(5);
    buffer.add(3);


    const uint8_t graphHeight = display.getHeight() - 10U; // TODO: magic number, because we need space for text too
    int maxValue = buffer.getMaxValue();

    for (uint16_t i = 0U; (i < buffer.count()) && (i < display.getWidth()); i++)
    {
        int sampleValue = buffer.get(i);

        // data normalization to nicely fit to screen low/high values
        sampleValue = uint8_t( (float(sampleValue) / float(maxValue)) *graphHeight);

        display.drawLine(i, 0, i, sampleValue);
    }

    display.paint();

#if 0
    itsDisplay.clearDisplay();

    // show legend
    uint8_t pulseValue = data->getSample(0U);
    drawNumber(pulseValue, 0U, 0U);
    drawText(conf.pulseConfig.pulseLabel, 18U, 0U);
    

    // TODO: dirty hack, we want to show value only when
    // showing graph for pulses per minute.
    if(conf.pulseConfig.doseLabel != "")
    {
        // TODO use a wrapper for writting numbers
        float doseValue = data->getDose();
        itsDisplay.setTextSize(0);
        itsDisplay.setTextColor(BLACK);
        itsDisplay.setCursor(36, 0);
        itsDisplay.print(doseValue);

        drawText(conf.pulseConfig.doseLabel, 59U, 0U);
    }


    // show graph
    const uint8_t graphHeight = 40U;
    sample_t maxValue = data->getMaxSampleValue();

    for (uint16_t i = 0U; (i < data->getSampleCount()) && (i < LCDWIDTH); i++)
    {
        sample_t sampleValue = data->getSample(i);
        
        // data normalization
        sampleValue = uint8_t( (float(sampleValue) / float(maxValue)) *graphHeight);        

        const uint16_t x = LCDWIDTH - i - 1U;
        itsDisplay.drawLine(x, itsDisplay.height(), x, itsDisplay.height() - sampleValue, BLACK);
    }

    itsDisplay.display();
#endif


}
